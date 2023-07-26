<h1 align="center">
	fract’ol
</h1>

<p align="center">
  <img src="https://github.com/riceset/riceset/blob/main/42_badges/fract-ole.png" alt="Fract'ol fract-ol 42 project badge"/>
</p>

## Summary
> <i>One of the first graphical projects at 42 school, fract-ol generates beautiful fractals from the complex numbers of an iterative mathematical construct.</i>
> <i>A fractal is a fragmented geometrical figure that infinitely repeats itself at smaller scales. This project uses the school's graphical library, MiniLibX.</i>

## Getting started
First, clone this repository and `cd` into it:

```zsh
$ git clone https://github.com/riceset/fract-ol; cd fract-ol
```

Compile using `make`:
```
make
```

## Executing Fract-ol

At execution time, you must specify a fractal to display. You may also provide other optional parameters:

```shell
./fractol <type> <options>
```

Types are :
* ```mandelbrot```: Mandelbrot fractal
* ```julia```: Julia fractal

For the Julia fractal set (and only this set), two additional parameters can be specified as calculation values. These represent a complex number that will change the shape of the Julia fractal. They must be fractional numbers between 2.0 and -2.0. For example:

```shell
./fractol julia 0.285 -0.01
```

## Mandelbrot set
![image](https://github.com/riceset/fract-ol/assets/48802655/eff9b775-4cd5-4a28-ade8-6802709f37f5)
![image](https://github.com/riceset/fract-ol/assets/48802655/9a7e3464-1cc7-4bfb-82c5-6ec2e6d1cc30)

## Julia set
![image](https://github.com/riceset/fract-ol/assets/48802655/5dae7320-ef11-49de-9869-91f9763ee7da)
![image](https://github.com/riceset/fract-ol/assets/48802655/86275fc7-04a5-4022-bfbb-6aa732ec0da4)

