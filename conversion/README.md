# Conversion utility

## About

A simple conversion utility allowing the user to convert from/to Kelvin, Celsius and Fahrenheit.

## Motivation

* Separating temperature conversion logic from I/O operations.
* Making sure there are no loopholes in the program flow.
* Soft spots: `do ... while` and `?:` (ab)use.

## Compiling

Run `make` to compile, `make clean` to remove `.o` files and `make mrproper` to remove the executable and the `.o` files.

## Running the conversion utility

```
$ ./main 
### Choice of temperature scale ###
1 - Kelvin
2 - Celsius
3 - Fahrenheit
Choose temperature scale to convert from (0 to quit): 1

Enter temperature to convert : 278.15

### Temperature scale to convert to ###
2 - Celsius
3 - Fahrenheit
Choose temperature scale to convert to: 2

A temperature of 278.15K corresponds to 5.00C.

### Choice of temperature scale ###
1 - Kelvin
2 - Celsius
3 - Fahrenheit
Choose temperature scale to convert from (0 to quit): 0
### End of program ###

```

## TODO

* `scanf` is _assumed_ to read integers
* Missing comments
