<h1 align="center">
	ft_printf
</h1>

<p align="center">
	<b><i>Because ft_putnbr() and ft_putstr() aren’t enough.</i></b><br>
</p>

## Summary

> The goal of this project is pretty straightforward. You will recode `printf()`.
> You will mainly learn about using a variable number of arguments.

## Getting started

First, clone this repository and `cd` into it:

```zsh
$ git clone https://github.com/riceset/printf; cd ft_printf
```

Compile the library with:

```zsh
$ make
```

You can test the `ft_printf()` function by creating a new file and including the `ft_printf.h` header file:

```c
#include "ft_printf.h"
```

## Caveats

This version of `printf()` only supports the following conversions:
- ***%c***
- ***%s***
- ***%p***
- ***%d***
- ***%i***
- ***%u***
- ***%x***
- ***%X***
- ***%%***
