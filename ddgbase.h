#ifndef _DDGBASE
#define _DDGBASE
#include <string.h>
#include <vector>
#include <cstdint>
namespace ddg{

    template <typename T = int>
    T base2(T number)
    {
        using int_type = T;

        int_type ret = 0;
        std::vector<int_type> aux;
        int index = 0;

        while(number>0)
        {
            aux.push_back(number%2);
            number = number/2;
            index++;
        }
        for(int i = index-1; i>=0; --i)
        {
            ret = ret*10 + aux[i];
        }
        return ret;
    }

    template <typename T = int>
    T base2(std::string number)
    {
        using int_type = T;

        int_type ret = 0;
        std::vector<int_type> aux;
        std::vector<int> aux3;
        int index = 0;
        int index3 = 0;

        while(number.length()>0)
        {
            if(number[number.length()-1]-48 > 9)
                aux.push_back(number[number.length() - 1] - 55);
            else
                aux.push_back(number[number.length() - 1] - 48);
            number.pop_back();
            index++;
        }
        for(int i = index - 1; i>=0; --i)
        {
            std::vector<int_type> aux2 = {};
            while(aux[i]>0)
            {
                aux2.push_back(aux[i]%2);
                aux[i] /= 2;
            }
            for(int i = 3; i>=0; --i)
            {
                std::cout<<aux2[i]<<'\n';
                aux3.push_back(aux2[i]);
                index3++;
            }
        }
        for(int i = 0; i<index3; ++i)
        {
            ret = ret*10 + aux3[i];
        }

        return ret;
    }

    template <typename T>
    std::string base2_s(T number)
    {
        using int_type = T;

        std::string ret = "";
        std::vector<int_type> aux;
        int index = 0;

        while(number>0)
        {
            aux.push_back(number%2);
            number = number/2;
            index++;
        }
        for(int i = index - 1; i>=0; --i)
        {
            ret = ret + (char)(aux[i]+'0');
        }

        return ret;
    }

    std::string base2_s(std::string number)
    {
        std::string ret = "";
        std::vector<char> aux;
        int index = 0;

        while(number.length()>0)
        {
            aux.push_back(number[number.length() - 1]);
            number.pop_back();
            index++;
        }
        for(int i = index - 1; i>=0; --i)
        {
            switch(aux[i]){
                case '0': 
                    ret = ret + "0000";
                    break;
                case '1':
                    ret = ret + "0001";
                    break;
                case '2':
                    ret = ret + "0010";
                    break;
                case '3':
                    ret = ret + "0011";
                    break;
                case '4':
                    ret = ret + "0100";
                    break;
                case '5':
                    ret = ret + "0101";
                    break;
                case '6':
                    ret = ret + "0110";
                    break;
                case '7':
                    ret = ret + "0111";
                    break;
                case '8':
                    ret = ret + "1000";
                    break;
                case '9':
                    ret = ret + "1001";
                    break;
                case 'A':
                    ret = ret + "1010";
                    break;
                case 'B':
                    ret = ret + "1011";
                    break;
                case 'C':
                    ret = ret + "1100";
                    break;
                case 'D':
                    ret = ret + "1101";
                    break;
                case 'E':
                    ret = ret + "1110";
                    break;
                case 'F':
                    ret = ret + "1111";
                    break;
            }
        }
        
        int j = 0;
        while(ret[j] == '0')
        {
            j++;
        }

        return ret.substr(j);
    }


    template <typename T = int>
    T base10(T number)
    {
        using int_type = T;

        int index = 0;
        std::vector<int_type> aux;
        int_type ret = 0;

        while(number>0)
        {
            if(number%10 == 0 || number%10 == 1)
            {
                 aux.push_back(number%10);
                 number = number/10;
                 index++;
            }
            else
                throw std::runtime_error("Number it's not binary");
        }
        for(int i = index - 1; i>=0; --i)
        {
            ret = ret*2 + aux[i];
        }

        return ret;
    }
    
    template <typename T = int>
    T base10(std::string number)
    {
        using int_type = T;

        int_type ret = 0;
        std::vector<int_type> aux;
        int index = 0;

        while(number.length()>0)
        {
            if(number[number.length()-1]-48 > 9)
                aux.push_back(number[number.length() - 1] - 55);
            else
                aux.push_back(number[number.length()-1]-48);
            number.pop_back();
            index++;
        }
        for(int i = index - 1; i>=0; --i)
        {
            ret = ret*16 + aux[i];
        }

        return ret;
    }

    template <typename T>
    std::string base16(T number)
    {
        std::vector<char> aux;
        std::string ret = "";

        while(number > 0)
        {
            auto remainder = number % 16;
            if(remainder > 9)
                aux.push_back('A' + remainder - 10);
            else
                aux.push_back('0' + remainder);

            number/=16;
        }
        for(int i = aux.size() - 1; i >= 0; --i)
        {
            ret = ret + aux[i];
        }

        return ret;
    }
}

#endif