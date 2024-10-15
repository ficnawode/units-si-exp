# SI COMPILE TIME UNITS LIBRARY EXPERIMENT

This is a draft/sandbox of an SI unit library idea I had.

Since all units derive from SI units and the math between them is well defined, it is possible to implement this logic in C++.

Limitations: no fractional powers, no unit checking at C++ standard math functions.

# Setup

```
mkdir build && cd build
```

```
cmake ..
```

```
ninja
```

```
ctest
```

# Example

The math library will trace units throughout operations and will NOT allow you to add two quantities of different units (even at compile time!).

Faraday's equation for voltage induced by magnetic field states:
$$
e = N\frac{d\phi}{dt}
$$
Where:
$$
\phi = BAcos(\theta)
$$
```cpp
// Lengths a, b defined in centimeters
auto length_a = 1.0_cm;
auto length_b = 2.0_cm;

// Dimensionless floating point quantity
auto cos_theta = 1.0;

// B defined in teslas
auto B = 1.0_T;

// Area - induced unit: m^2
auto Area = length_a * length_b;

// Flux - induced unit - T*m^2
auto flux = B * Area * cos_theta;

// Dimensionless quantity
const float N = 1.0;

// The result will automatically be given in volts (kg*m^2/(A*s^3))
auto voltage = flux / 1.0_s * N;
```

in this case 

```cpp
std::cout << voltage.to_string() << std::endl;
```

returns 

```
0.000200 m^{2} A^{-1} s^{-3} kg^{1}
```