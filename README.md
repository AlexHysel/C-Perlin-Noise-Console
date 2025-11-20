# C-Perlin-Noise-Console

This repository contains a simple, customizable implementation of **Perlin Noise** in C, designed for generating procedural content such as textures, terrain, or dynamic visual effects. The implementation includes functionality to display the noise as a grayscale character map in the console, offering a real-time visualization of the generated noise field.
<img width="3831" height="2091" alt="Screenshot from 2025-11-20 16-31-01" src="https://github.com/user-attachments/assets/29bf8f5d-2ad8-4cba-85f9-fe59f014df49" />

## 🛠️ Features

  * **2D Perlin Noise Generation:** Generates coherent, gradient-based noise.
  * **Real-time Visualization:** The `main` function demonstrates how to animate the noise by incrementally changing the grid angles over time, displaying the result as a character map.
  * **Modular Design:** Separated functions for core logic, mathematical utilities, and display handling.
  * **Configurable Constants:** Easily change parameters like character set, contrast, and display ratio via preprocessor directives in `hpn.h`.

## 📂 Project Structure

| File | Description |
| :--- | :--- |
| `hpn.h` | Header file containing necessary includes, structure definitions (`t_cell`), and function prototypes. |
| `hpn.c` | Core Perlin Noise logic (`perlin_noise`, `interpolate`, `increase_contrast`). |
| `hpn_math.c` | Two curve functions, dot product and linear interpolation (LERP) |
| `hpn_grid.c` | Functions to create grid with random angles, increment all of them (to animate the noise) and get cell |
| `hpn_display.c` | Functions to dislplay the noise and grid |
| `test.c` | Example executable demonstrating usage, grid creation, real-time animation, and display. |

## ⚙️ How to Build and Run

### Compilation

Compile the library using Makefile:

```bash
make
```

Then compile test:

```bash
gcc test.c perlin_noise.a -lm
```

The `-lm` flag links the math library.

### Execution

The program expects at least one command-line argument for the **seed**. You can optionally specify the grid dimensions and the display step.

```bash
./a.out <seed> [grid_width] [grid_height] [display_step]
```

#### Example Usage:

1.  **Basic (Default 2x2 grid, step 0.02):**

    ```bash
    ./hpn 1234
    ```

2.  **Custom Grid Size (4x4 grid):**

    ```bash
    ./hpn 1234 4 4
    ```

3.  **Bigger scale (Smaller step):**

    ```bash
    ./hpn 1234 4 4 0.01
    ```

-----

## 💻 Implementation Details

### `perlin_noise` Flow

The `perlin_noise` function calculates the noise value for a given coordinate $(x, y)$ following the standard Perlin Noise algorithm:
1.  **Create Grid** Create grid with random angles (0 - 359)
2.  **Determine Cell Coordinates:** Find the integer grid cell $(cell_x, cell_y)$ containing the point $(x, y)$.
3.  **Get Fractional Coordinates:** Calculate the fractional coordinates $(x_{frac}, y_{frac})$ within the cell.
4.  **Calculate Dot Products:** Compute the **influence** of the four surrounding gradient vectors (stored in the `t_cell` structure) by taking the **dot product** of each gradient vector with the displacement vector from the corner to $(x_{frac}, y_{frac})$.
5.  **Interpolation:** Perform **bidirectional linear interpolation** (**Bilinear Interpolation**) to blend the four dot product results. The fractional coordinates are first smoothed using `perlin_curve` or `quintic_curve`.
6.  **Contrast Adjustment:** Apply the `increase_contrast` function to the final interpolated value (otherwise the result will be too average).

### Key Functions

| Function | Purpose |
| :--- | :--- |
| `perlin_noise` | Main function to compute the noise value at $(x, y)$. |
| `interpolate` | Calculates the interpolated noise value from the four corner dot products. |
| `increase_contrast` | Applies a contrast effect using the `CONTRAST_EXPONENT`. |
| `dot_product` | Calculates the influence of a gradient vector. |
| `lerp` | Simple linear interpolation: $x + t \times (y - x)$. |
| `perlin_curve` / `quintic_curve` | The smoothing function used before interpolation. |

## 🌟 Configuration (`hpn.h`)

You can customize the output by modifying the following preprocessor definitions in `hpn.h`:

| Constant | Default Value | Description |
| :--- | :--- | :--- |
| `CHARSET` | \" \.,:;+\!/?7J%&\#@"| The string of characters used to map the noise values to a grayscale representation. | 
|`CHAR_RATIO`|`2.0`| Adjusts the aspect ratio of the characters (since console characters are typically taller than they are wide). | 
|`CONTRAST_EXPONENT`|`0.35` | Controls the sharpness of the noise. Lower values increase contrast. |
