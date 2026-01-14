#include <gtk/gtk.h>

void end_program (GtkWidget *wid, gpointer ptr)
{
	gtk_main_quit ();
}

void row_selected (GtkWidget *wid, gpointer ptr)
{
	GtkTreeSelection *sel;
	GtkTreeModel *model;
	GtkTreeIter iter;
	char *option;

	sel = gtk_tree_view_get_selection (GTK_TREE_VIEW (wid));
	if (gtk_tree_selection_get_selected (sel, &model, &iter))
	{
		gtk_tree_model_get (model, &iter, 0, &option, -1);
		printf ("The selected row contains the text %s\n", option);
	}
}

void open_dialog (GtkWidget *wid, gpointer ptr)
{
	GtkWidget *dlg = gtk_dialog_new_with_buttons (
		"My dialog",
		GTK_WINDOW (ptr),
		GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
		"Cancel", 0, "OK", 1, NULL
	);

	int result = gtk_dialog_run (GTK_DIALOG (dlg));
	gtk_widget_destroy (dlg);
	printf ("Return code = %d\n", result);
}

int main (int argc, char *argv[])
{
	gtk_init (&argc, &argv);

	GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	GtkWidget *btn = gtk_button_new_with_label ("Open modal");
	g_signal_connect (btn, "clicked", G_CALLBACK (open_dialog), NULL);
	g_signal_connect (win, "delete_event", G_CALLBACK (end_program),
		NULL);

	int pos = 0;

	GtkListStore *ls = gtk_list_store_new (2, G_TYPE_STRING,
		GDK_TYPE_PIXBUF);
	GdkPixbuf *icon = gtk_icon_theme_load_icon (
		gtk_icon_theme_get_default (), "dialog-ok-apply", 32, 0, NULL);
	gtk_list_store_insert_with_values (ls, NULL, pos++, 0,
		"Option 1", 1, icon, -1);
	gtk_list_store_insert_with_values (ls, NULL, pos++, 0,
		"Option 2", 1, icon, -1);
	gtk_list_store_insert_with_values (ls, NULL, pos++, 0,
		"Option 3", 1, icon, -1);

	GtkWidget *tv = gtk_tree_view_new_with_model (GTK_TREE_MODEL (ls));

	GtkCellRenderer *prend = gtk_cell_renderer_pixbuf_new ();
	GtkCellRenderer *trend = gtk_cell_renderer_text_new ();

	gtk_tree_view_insert_column_with_attributes (
		GTK_TREE_VIEW (tv), -1, "Icon", prend, "pixbuf", 1, NULL);
	gtk_tree_view_insert_column_with_attributes (
		GTK_TREE_VIEW (tv), -1, "Option", trend, "text", 0, NULL);

	g_signal_connect (
		tv, "cursor-changed", G_CALLBACK (row_selected), NULL);

	GtkWidget *grd = gtk_grid_new ();
	gtk_grid_attach (GTK_GRID (grd), tv, 0, 0, 1, 1);
	gtk_grid_attach (GTK_GRID (grd), btn, 0, 1, 1, 1);
	gtk_container_add (GTK_CONTAINER (win), grd);
	gtk_widget_show_all (win);
	gtk_main ();
	return 0;
}
