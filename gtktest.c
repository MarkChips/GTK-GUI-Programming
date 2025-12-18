#include <gtk/gtk.h>

int count = 0;
GtkWidget *txt;

void end_program (GtkWidget *wid, gpointer ptr)
{
	gtk_main_quit ();
}

void check_toggle (GtkWidget *wid, gpointer ptr)
{
	printf ("The state of the button is %d\n",
		gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (wid)));
}

void copy_text (GtkWidget *wid, gpointer ptr)
{
	const char *input = gtk_entry_get_text (GTK_ENTRY (txt));
	gtk_label_set_text (GTK_LABEL (ptr), input);
}

void count_button (GtkWidget *wid, gpointer ptr)
{
	char buffer[30];
	count++;
	sprintf (buffer, "Button pressed %d times", count);
	gtk_label_set_text (GTK_LABEL (ptr), buffer);
}

int main (int argc, char *argv[])
{
	gtk_init (&argc, &argv);
	
	GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	GtkWidget *btn = gtk_button_new_with_label ("Close window");
	g_signal_connect (btn, "clicked", G_CALLBACK (end_program), NULL);
	g_signal_connect (win, "delete_event", G_CALLBACK (end_program),
		NULL);
		
	GtkWidget *lbl = gtk_label_new ("My label");

	GtkWidget *rad1 = gtk_radio_button_new_with_label (NULL, "Button 1");
	GSList *group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (rad1));
	GtkWidget *rad2 = gtk_radio_button_new_with_label (group, "Button 2");

	GtkAdjustment *adj = gtk_adjustment_new (0, -10, 10, 1, 0, 0);
	txt = gtk_spin_button_new (adj, 0, 0);

	GtkWidget *grd = gtk_grid_new ();
	gtk_grid_attach (GTK_GRID (grd), rad1, 0, 0, 1, 1);
	gtk_grid_attach (GTK_GRID (grd), rad2, 1, 0, 1, 1);
	gtk_grid_attach (GTK_GRID (grd), btn, 0, 1, 1, 1);
	gtk_grid_attach (GTK_GRID (grd), txt, 1, 1, 1, 1);
	gtk_container_add (GTK_CONTAINER (win), grd);
	gtk_widget_show_all (win);
	gtk_main ();
	return 0;
}
