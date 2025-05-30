# cpp-module-06
This module is designed to demonstrate the different casts in CPP.

| Purpose                                                       | Use This Cast      |
| ------------------------------------------------------------- | ------------------ |
| Numeric conversion, pointer upcast, well-defined type changes | `static_cast`      |
| Safe polymorphic downcasting                                  | `dynamic_cast`     |
| Modify const/volatile qualifiers                              | `const_cast`       |
| Dangerous bit-level reinterpretation                          | `reinterpret_cast` |


## Ex00: task 

    parms: string literal => belongs to one of these scalars {char, int, float, double}
    Except for 'char', only decimal notation will be used 
    if char is non displayable = 
    
    1 - casting between scalars, we use static_cast
    2- determine type: + if (len == 1 and not digit) : return char
                    + if (is_special_float_double ==  -inff, +inff
                                    and nanf. "nan", "inf", "+inf", 
                                "-inf", "nanf", "nanf", "inff", etc) : return float or double ? 
                    + if  (has_float_notation == 'f') return (float )
                    + if (only degit , may have + or - ) return int 
                    + if (has . or exponent e/E and is valid) return double

    Errors:
    1 - If a conversion to char is not displayable, prints an informative message.
        such as : "Non displayable"
    2 - If a conversion does not make any sense or overflows, display a message to inform
        the user that the type conversion is impossible. 