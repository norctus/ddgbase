# Base conversion functions (header only)
## Supported bases and function names:
1. base2 =  

   -base2(int_type) (takes an int parameter of chosen type and returns a binary int of the same type)
   -base2(std::string ) or base2(const char*) (takes a string parameter of base16 and returns a binary int)

### **These 2 functions can be used only for _small_ decimal and hexadecimal numbers**

    -base2_s(int_type) (same as base2() but returns a string)
    -base2_s(std::string) or base2_s(const char*) (for hexa)

### **These 2 functions are used for _big_ numbers too**

2. base10 =

   -base10(int_type) (takes an int in binary format)
   -base10(std::string) or base10(const char*) (converts from base2 or base16 to base10)

3. base16 = 

   -base16(int_type) (converts from decimal to hexadecimal)
   -base16(std::string) or base16(const char*) (converts from binary to hexadecimal)

