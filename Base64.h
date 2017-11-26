
#ifndef BASE64_H
#define BASE64_H

#include <vector>
#include <string>
namespace Base64{
    std::string base64_decode(const std::string &);


    std::string DecryptB64(std::string s){
        s = base64_decode(s);
        return s;
    }

    const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string base64_decode(const std::string &s){
        std::string ret;
        int val = 0;
        int time = 0;
        int timeinner = 0;
        const unsigned int b255 = 0xFF;
        const unsigned int b7 = 0x7;
        const unsigned int b3 = 0x3;

        for(const auto &c : s){
            if('-' == (c)){
                val = (val << 6);
            }else{
                std::size_t found = BASE64_CODES.find(c);
                val = (val << 6) + found;
            }
            if(time==1){
                int d = 0;
                if(timeinner==0){
                    d = ((val>>4) & b255);
                    val = val & b7;
                    time=0;
                }if(timeinner==1){
                    d = ((val>>2) & b255);
                    val = val & b3;
                    time=0;
                }if(timeinner==2){
                    d = ((val) & b255);
                    val = 0;
                    time=-1;
                    timeinner = -1;
                }
                timeinner++;
                char charAt = ('0' +  d - 48);
                ret.push_back( charAt );
            }
            time++;

        }
        return ret;

    }

    std::string base64_encode(const std::string &);

    std::string EncryptB64(std::string s){
        s = base64_encode(s);
        return s;
    }


    std::string base64_encode(const std::string &s){
        std::string ret;
        int val = 0;
        int bits = -6;
        const unsigned int b63 = 0x3F;

        for(const auto &c : s){
            val = (val << 8) + c;
            bits += 8;
            while(bits >= 0){
                ret.push_back(BASE64_CODES[(val >> bits) & b63]);
                bits -= 6;
            }
        }
        if(bits > -6){
            ret.push_back(BASE64_CODES[((val << 8) >> (bits+8)) & b63]);
        }
        while(ret.size()%4)
            ret.push_back('-');
        return ret;

    }


}

#endif // BASE64_H
