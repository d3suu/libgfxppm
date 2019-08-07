# libgfxppm
Simple C PPM Image Library

## Warning!

This library works only with "P6" PPM files, and is under heavy development. At this moment, only importing does not work. Everything else is working, but not error proof!

## Usage

### Create/Import PPM File
Created/Import PPM File will be stored in structure `struct gfx_PPMStruct`.

#### Creating
```C
// This will generate PPM structure, 10px wide and high, with RGB #000000
struct gfx_PPMStruct* MyPPMStructure = gfx_PPMSetup(10, 10, 0, 0, 0);
```

#### Importing
```C
// This will generate PPM structure, based on imported image
struct gfx_PPMStruct* MyPPMStructure = gfx_PPMImport("./mypicture.ppm");
```

### Editing PPM File

#### Set Pixel Colour
```C
// This will set pixel on X:5 Y:10, colour RGB #213700
gfx_PPMSetPixel(5, 10, MyPPMStructure, 0x21, 0x37, 0x00);
```

#### Get Pixel Colour
```C
// This will get colour of pixel on X:5 Y:10
struct gfx_PPMPixel* MyPixel = gfx_PPMGetPixel(5, 10, MyPPMStructure);
char R = MyPixel->R;
char G = MyPixel->G;
char B = MyPixel->B;
free(MyPixel);
```

### Closing file

#### Exporting modified image
```C
// This will export our structure to "abc.ppm" file
gfx_PPMExport(MyPPMStructure, "abc.ppm");
```

#### Clearing memory after image
```C
// This will clear memory after image modification/creation
gfx_PPMFree(MyPPMStructure);
```
