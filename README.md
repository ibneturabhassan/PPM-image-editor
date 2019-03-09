# PPM-image-editor
PPM image editor is a simple image editing software written in C language that is used to edit ppm images with magic number P3.
PPM stands for Portable Pix Map. It is a lowest common denominator color image file format. A PPM file consists of a sequence of one or more PPM images. There are no data, delimiters, or padding before, after, or between images. Following are some characteristics of PPM files
- There is exactly one image in a file.
- The magic number is P3 instead of P6.
- Each sample in the raster is represented as an ASCII decimal number (of arbitrary size).
- Each sample in the raster has white space before and after it. There must be at least one character of white space between any two samples, but there is no maximum. There is no particular separation of one pixel from another -- just the required separation between the blue sample of one pixel from the red sample of the next pixel.
- No line should be longer than 70 characters.

#Features
- Negate Green
- Negate Red
- Negate Blue
- High Contrast
- Flatten Red
- Flatten Green
- Flatten Blue
- Greyscale Luminos
- Black and White contrast
- Noice
- Blur
