# GTK GUI Programming — MagPi "C & GUI Programming"

This repository contains code samples and executables created by following along with chapters in the [MagPi — C & GUI Programming](https://magpi.raspberrypi.com/) guide. Each program here corresponds to an exercise or project covered in the lesson series, providing a hands-on way to learn and explore GTK 3.0 programming basics.

## How to Use

1. **Clone the Repository:**
   ```sh
   git clone https://github.com/MarkChips/GTK-GUI-Programming.git
   cd C-Essentials
   ```

2. **Running the Programs:**
   Most lesson examples have already been compiled. You can run any executable by typing:
   ```sh
   ./<program_name>
   ```
   For example:
   ```sh
   ./arrays
   ```
   (This runs the compiled executable for the "arrays" chapter.)

   > **Note:**  
   > If you see a "Permission denied" error, you may need to make the file executable:  
   > `chmod +x <program_name>`

3. **Compiling from Source (Optional):**
   If you want to modify the source code or rebuild a program:
   ```sh
   gcc arrays.c -o arrays
   ```
   Replace `arrays.c` with any of the source files you want to compile.  
   Then run:
   ```sh
   ./arrays
   ```

## About

- This repo is an educational collection following the MagPi C programming guide.
- Each executable demonstrates basic C concepts, from input/output and variables to flow control, arrays, functions, and more.
- Source files have a `.c` extension; the corresponding executables have no extension.

## License

This project is for learning and personal use. Please credit MagPi and reference the original guide if you share or adapt these scripts.

---
Happy coding!
