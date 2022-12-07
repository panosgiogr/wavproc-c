// Author: Panagiotis Giovanos
//    SDI: 2000034
//Program: http://cgi.di.uoa.gr/~ip/iphw2021_2.pdf
//Modes Executed 1,2,3,4

/*library declaration*/
#include <stdio.h>
/*library declaration*/

/*constant variables declaration*/
#define MODE 1
/*constant variables declaration*/
int bp1 = 0; // byte position for power calculation

int calc_pow(int base, int exp) // power calculation base^exp
{

    int sum = 1;
    if (exp == 0)
    {
        sum = 1;
    }
    else
    {
        while (exp != 0)
        {
            sum = sum * base;
            --exp;
        }
    }
    return sum;
}

int conv_hex_to_dec(unsigned char ch) // convert hexadecimal byte to decimal
{

    int a = 0;
    int b = 0;
    //hex to decimal
    if(ch==0x00){a=0;b=0;}else if(ch==0x01){a=0;b=1;}else if(ch==0x02){a=0;b=2;}else if(ch==0x03){a=0;b=3;}else if(ch==0x04){a=0;b=4;}else if(ch==0x05){a=0;b=5;}else if(ch==0x06){a=0;b=6;}else if(ch==0x07){a=0;b=7;}else if(ch==0x08){a=0;b=8;}else if(ch==0x09){a=0;b=9;}else if(ch==0x10){a=1;b=0;}else if(ch==0x11){a=1;b=1;}else if(ch==0x12){a=1;b=2;}else if(ch==0x13){a=1;b=3;}else if(ch==0x14){a=1;b=4;}else if(ch==0x15){a=1;b=5;}else if(ch==0x16){a=1;b=6;}else if(ch==0x17){a=1;b=7;}else if(ch==0x18){a=1;b=8;}else if(ch==0x19){a=1;b=9;}else if(ch==0x1a){a=1;b=10;}else if(ch==0x1b){a=1;b=11;}else if(ch==0x1c){a=1;b=12;}else if(ch==0x1d){a=1;b=13;}else if(ch==0x1e){a=1;b=14;}else if(ch==0x1f){a=1;b=15;}else if(ch==0x20){a=2;b=0;}else if(ch==0x21){a=2;b=1;}else if(ch==0x22){a=2;b=2;}else if(ch==0x23){a=2;b=3;}else if(ch==0x24){a=2;b=4;}else if(ch==0x25){a=2;b=5;}else if(ch==0x26){a=2;b=6;}else if(ch==0x27){a=2;b=7;}else if(ch==0x28){a=2;b=8;}else if(ch==0x29){a=2;b=9;}else if(ch==0x2a){a=2;b=10;}else if(ch==0x2b){a=2;b=11;}else if(ch==0x2c){a=2;b=12;}else if(ch==0x2d){a=2;b=13;}else if(ch==0x2e){a=2;b=14;}else if(ch==0x2f){a=2;b=15;}else if(ch==0x30){a=3;b=0;}else if(ch==0x31){a=3;b=1;}else if(ch==0x32){a=3;b=2;}else if(ch==0x33){a=3;b=3;}else if(ch==0x34){a=3;b=4;}else if(ch==0x35){a=3;b=5;}else if(ch==0x36){a=3;b=6;}else if(ch==0x37){a=3;b=7;}else if(ch==0x38){a=3;b=8;}else if(ch==0x39){a=3;b=9;}else if(ch==0x3a){a=3;b=10;}else if(ch==0x3b){a=3;b=11;}else if(ch==0x3c){a=3;b=12;}else if(ch==0x3d){a=3;b=13;}else if(ch==0x3e){a=3;b=14;}else if(ch==0x3f){a=3;b=15;}else if(ch==0x40){a=4;b=0;}else if(ch==0x41){a=4;b=1;}else if(ch==0x42){a=4;b=2;}else if(ch==0x43){a=4;b=3;}else if(ch==0x44){a=4;b=4;}else if(ch==0x45){a=4;b=5;}else if(ch==0x46){a=4;b=6;}else if(ch==0x47){a=4;b=7;}else if(ch==0x48){a=4;b=8;}else if(ch==0x49){a=4;b=9;}else if(ch==0x4a){a=4;b=10;}else if(ch==0x4b){a=4;b=11;}else if(ch==0x4c){a=4;b=12;}else if(ch==0x4d){a=4;b=13;}else if(ch==0x4e){a=4;b=14;}else if(ch==0x4f){a=4;b=15;}else if(ch==0x50){a=5;b=0;}else if(ch==0x51){a=5;b=1;}else if(ch==0x52){a=5;b=2;}else if(ch==0x53){a=5;b=3;}else if(ch==0x54){a=5;b=4;}else if(ch==0x55){a=5;b=5;}else if(ch==0x56){a=5;b=6;}else if(ch==0x57){a=5;b=7;}else if(ch==0x58){a=5;b=8;}else if(ch==0x59){a=5;b=9;}else if(ch==0x5a){a=5;b=10;}else if(ch==0x5b){a=5;b=11;}else if(ch==0x5c){a=5;b=12;}else if(ch==0x5d){a=5;b=13;}else if(ch==0x5e){a=5;b=14;}else if(ch==0x5f){a=5;b=15;}else if(ch==0x60){a=6;b=0;}else if(ch==0x61){a=6;b=1;}else if(ch==0x62){a=6;b=2;}else if(ch==0x63){a=6;b=3;}else if(ch==0x64){a=6;b=4;}else if(ch==0x65){a=6;b=5;}else if(ch==0x66){a=6;b=6;}else if(ch==0x67){a=6;b=7;}else if(ch==0x68){a=6;b=8;}else if(ch==0x69){a=6;b=9;}else if(ch==0x6a){a=6;b=10;}else if(ch==0x6b){a=6;b=11;}else if(ch==0x6c){a=6;b=12;}else if(ch==0x6d){a=6;b=13;}else if(ch==0x6e){a=6;b=14;}else if(ch==0x6f){a=6;b=15;}else if(ch==0x70){a=7;b=0;}else if(ch==0x71){a=7;b=1;}else if(ch==0x72){a=7;b=2;}else if(ch==0x73){a=7;b=3;}else if(ch==0x74){a=7;b=4;}else if(ch==0x75){a=7;b=5;}else if(ch==0x76){a=7;b=6;}else if(ch==0x77){a=7;b=7;}else if(ch==0x78){a=7;b=8;}else if(ch==0x79){a=7;b=9;}else if(ch==0x7a){a=7;b=10;}else if(ch==0x7b){a=7;b=11;}else if(ch==0x7c){a=7;b=12;}else if(ch==0x7d){a=7;b=13;}else if(ch==0x7e){a=7;b=14;}else if(ch==0x7f){a=7;b=15;}else if(ch==0x80){a=8;b=0;}else if(ch==0x81){a=8;b=1;}else if(ch==0x82){a=8;b=2;}else if(ch==0x83){a=8;b=3;}else if(ch==0x84){a=8;b=4;}else if(ch==0x85){a=8;b=5;}else if(ch==0x86){a=8;b=6;}else if(ch==0x87){a=8;b=7;}else if(ch==0x88){a=8;b=8;}else if(ch==0x89){a=8;b=9;}else if(ch==0x8a){a=8;b=10;}else if(ch==0x8b){a=8;b=11;}else if(ch==0x8c){a=8;b=12;}else if(ch==0x8d){a=8;b=13;}else if(ch==0x8e){a=8;b=14;}else if(ch==0x8f){a=8;b=15;}else if(ch==0x90){a=9;b=0;}else if(ch==0x91){a=9;b=1;}else if(ch==0x92){a=9;b=2;}else if(ch==0x93){a=9;b=3;}else if(ch==0x94){a=9;b=4;}else if(ch==0x95){a=9;b=5;}else if(ch==0x96){a=9;b=6;}else if(ch==0x97){a=9;b=7;}else if(ch==0x98){a=9;b=8;}else if(ch==0x99){a=9;b=9;}else if(ch==0x9a){a=9;b=10;}else if(ch==0x9b){a=9;b=11;}else if(ch==0x9c){a=9;b=12;}else if(ch==0x9d){a=9;b=13;}else if(ch==0x9e){a=9;b=14;}else if(ch==0x9f){a=9;b=15;}else if(ch==0xa0){a=10;b=0;}else if(ch==0xa1){a=10;b=1;}else if(ch==0xa2){a=10;b=2;}else if(ch==0xa3){a=10;b=3;}else if(ch==0xa4){a=10;b=4;}else if(ch==0xa5){a=10;b=5;}else if(ch==0xa6){a=10;b=6;}else if(ch==0xa7){a=10;b=7;}else if(ch==0xa8){a=10;b=8;}else if(ch==0xa9){a=10;b=9;}else if(ch==0xaa){a=10;b=10;}else if(ch==0xab){a=10;b=11;}else if(ch==0xac){a=10;b=12;}else if(ch==0xad){a=10;b=13;}else if(ch==0xae){a=10;b=14;}else if(ch==0xaf){a=10;b=15;}else if(ch==0xb0){a=11;b=0;}else if(ch==0xb1){a=11;b=1;}else if(ch==0xb2){a=11;b=2;}else if(ch==0xb3){a=11;b=3;}else if(ch==0xb4){a=11;b=4;}else if(ch==0xb5){a=11;b=5;}else if(ch==0xb6){a=11;b=6;}else if(ch==0xb7){a=11;b=7;}else if(ch==0xb8){a=11;b=8;}else if(ch==0xb9){a=11;b=9;}else if(ch==0xba){a=11;b=10;}else if(ch==0xbb){a=11;b=11;}else if(ch==0xbc){a=11;b=12;}else if(ch==0xbd){a=11;b=13;}else if(ch==0xbe){a=11;b=14;}else if(ch==0xbf){a=11;b=15;}else if(ch==0xc0){a=12;b=0;}else if(ch==0xc1){a=12;b=1;}else if(ch==0xc2){a=12;b=2;}else if(ch==0xc3){a=12;b=3;}else if(ch==0xc4){a=12;b=4;}else if(ch==0xc5){a=12;b=5;}else if(ch==0xc6){a=12;b=6;}else if(ch==0xc7){a=12;b=7;}else if(ch==0xc8){a=12;b=8;}else if(ch==0xc9){a=12;b=9;}else if(ch==0xca){a=12;b=10;}else if(ch==0xcb){a=12;b=11;}else if(ch==0xcc){a=12;b=12;}else if(ch==0xcd){a=12;b=13;}else if(ch==0xce){a=12;b=14;}else if(ch==0xcf){a=12;b=15;}else if(ch==0xd0){a=13;b=0;}else if(ch==0xd1){a=13;b=1;}else if(ch==0xd2){a=13;b=2;}else if(ch==0xd3){a=13;b=3;}else if(ch==0xd4){a=13;b=4;}else if(ch==0xd5){a=13;b=5;}else if(ch==0xd6){a=13;b=6;}else if(ch==0xd7){a=13;b=7;}else if(ch==0xd8){a=13;b=8;}else if(ch==0xd9){a=13;b=9;}else if(ch==0xda){a=13;b=10;}else if(ch==0xdb){a=13;b=11;}else if(ch==0xdc){a=13;b=12;}else if(ch==0xdd){a=13;b=13;}else if(ch==0xde){a=13;b=14;}else if(ch==0xdf){a=13;b=15;}else if(ch==0xe0){a=14;b=0;}else if(ch==0xe1){a=14;b=1;}else if(ch==0xe2){a=14;b=2;}else if(ch==0xe3){a=14;b=3;}else if(ch==0xe4){a=14;b=4;}else if(ch==0xe5){a=14;b=5;}else if(ch==0xe6){a=14;b=6;}else if(ch==0xe7){a=14;b=7;}else if(ch==0xe8){a=14;b=8;}else if(ch==0xe9){a=14;b=9;}else if(ch==0xea){a=14;b=10;}else if(ch==0xeb){a=14;b=11;}else if(ch==0xec){a=14;b=12;}else if(ch==0xed){a=14;b=13;}else if(ch==0xee){a=14;b=14;}else if(ch==0xef){a=14;b=15;}else if(ch==0xf0){a=15;b=0;}else if(ch==0xf1){a=15;b=1;}else if(ch==0xf2){a=15;b=2;}else if(ch==0xf3){a=15;b=3;}else if(ch==0xf4){a=15;b=4;}else if(ch==0xf5){a=15;b=5;}else if(ch==0xf6){a=15;b=6;}else if(ch==0xf7){a=15;b=7;}else if(ch==0xf8){a=15;b=8;}else if(ch==0xf9){a=15;b=9;}else if(ch==0xfa){a=15;b=10;}else if(ch==0xfb){a=15;b=11;}else if(ch==0xfc){a=15;b=12;}else if(ch==0xfd){a=15;b=13;}else if(ch==0xfe){a=15;b=14;}else if(ch==0xff){a=15;b=15;}
    int temp_a, temp_b = 0;

    temp_a = a * calc_pow(16, bp1 + 1); // store temporarily a so it won't be altered
    bp1++;
    temp_b = b * calc_pow(16, bp1 - 1); // store temporarily b so it won't be altered
    bp1++;

    return temp_a + temp_b;
}
/*variable declaration*/
long long int riff, wave, fmt, size_of_file, size_of_format_chunck, wave_type_format, mono_stereo, sample_rate, bytes_sec, block_alignment, bits_sample, size_of_data_chunk, data = 0;
int size_of_file_count = 0;
int b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b40, b41, b42, b43, b44; // bytes used as buffer for mode4
int mode2_sample_rate, mode2_bytes_sec;
int mode4_file_size, mode4_format_chunck, mode4_mono_stereo, mode4_size_data_chunk, mode4_block_align, mode4_bytes_sec, mode4_bits_sample;
int mode4_last = 45; // begin from int
/*variable declaration*/

/*End of main*/
int main()
{
    bp1 = 0; // reset byte position
    unsigned int reader = 0;
    int count_byte = 1;
    while ((reader = getchar()) != EOF) /* read/print "abcde" from stdin */
    {
        size_of_file_count++;
        if (count_byte >= 1 && count_byte <= 4) // RIFF
        {
            riff += conv_hex_to_dec(reader); // add every byte to variable
            if (count_byte == 4) // if it is the last byte of riff then...
            {
                bp1 = 0;
            }
            if (MODE == 2 || MODE == 3 || MODE == 4) // write to file except from mode1
            {
                putchar(reader);
            }
        }
        else if (count_byte >= 5 && count_byte <= 8) // size of file
        {
            size_of_file += conv_hex_to_dec(reader);
            if (count_byte == 8)
            {
                bp1 = 0;
            }
            if (MODE == 2 || MODE == 3)
            {
                putchar(reader);
            }
        }
        else if (count_byte >= 9 && count_byte <= 12) // wave
        {
            wave += conv_hex_to_dec(reader);
            if (count_byte == 12)
            {
                bp1 = 0;
            }
            if (MODE == 2 || MODE == 3)
            {
                putchar(reader);
            }
        }
        else if (count_byte >= 13 && count_byte <= 16) // fmt
        {
            fmt += conv_hex_to_dec(reader);
            if (count_byte == 16)
            {
                bp1 = 0;
            }
            if (MODE == 2 || MODE == 3)
            {
                putchar(reader);
            }
        }
        else if (count_byte >= 17 && count_byte <= 20) // format chunck
        {
            size_of_format_chunck += conv_hex_to_dec(reader);
            if (count_byte == 20)
            {
                bp1 = 0;
            }
            if (MODE == 2 || MODE == 3)
            {
                putchar(reader);
            }
        }
        else if (count_byte >= 21 && count_byte <= 22) // wave type format
        {
            wave_type_format += conv_hex_to_dec(reader);
            if (count_byte == 22)
            {
                bp1 = 0;
            }
            if (MODE == 2 || MODE == 3)
            {
                putchar(reader);
            }
        }
        else if (count_byte >= 23 && count_byte <= 24) // mono /stereo
        {
            mono_stereo += conv_hex_to_dec(reader);
            if (count_byte == 24)
            {
                bp1 = 0;
                if (MODE == 2 || MODE == 3)
                {
                    //Bitshifting Url: https://en.wikipedia.org/wiki/Bitwise_operations_in_C
                    //bitshift every byte
                    b23 = mono_stereo & 255;
                    b24 = (mono_stereo >> 8) & 255; //Bitshift Right by 8 / (255)10=(11111111)2
                    putchar(b23);
                    putchar(b24);
                }
            }
        }
        else if (count_byte >= 25 && count_byte <= 28) // sample rate
        {
            sample_rate += conv_hex_to_dec(reader);
            if (count_byte == 28)
            {
                bp1 = 0;
                if (MODE == 2)
                {
                    mode2_sample_rate = sample_rate / 2;
                    b25 = mode2_sample_rate & 255;
                    b26 = (mode2_sample_rate >> 8) & 255;
                    b27 = (mode2_sample_rate >> 16) & 255;
                    b28 = (mode2_sample_rate >> 24) & 255;
                    putchar(b25);
                    putchar(b26);
                    putchar(b27);
                    putchar(b28);
                }
                else if (MODE == 3)
                {
                    mode2_sample_rate = sample_rate * 2;
                    b25 = mode2_sample_rate & 255;
                    b26 = (mode2_sample_rate >> 8) & 255;
                    b27 = (mode2_sample_rate >> 16) & 255;
                    b28 = (mode2_sample_rate >> 24) & 255;
                    putchar(b25);
                    putchar(b26);
                    putchar(b27);
                    putchar(b28);
                }
            }
        }
        else if (count_byte >= 29 && count_byte <= 32) //bytes / sec
        {
            bytes_sec += conv_hex_to_dec(reader);
            if (count_byte == 32)
            {
                bp1 = 0;
                if (MODE == 2)
                {
                    mode2_bytes_sec = bytes_sec / 2;
                    b29 = mode2_bytes_sec & 255;
                    b30 = (mode2_bytes_sec >> 8) & 255;
                    b31 = (mode2_bytes_sec >> 16) & 255;
                    b32 = (mode2_bytes_sec >> 24) & 255;
                    putchar(b29);
                    putchar(b30);
                    putchar(b31);
                    putchar(b32);
                }
                else if (MODE == 3)
                {
                    mode2_bytes_sec = bytes_sec * 2;
                    b29 = mode2_bytes_sec & 255;
                    b30 = (mode2_bytes_sec >> 8) & 255;
                    b31 = (mode2_bytes_sec >> 16) & 255;
                    b32 = (mode2_bytes_sec >> 24) & 255;
                    putchar(b29);
                    putchar(b30);
                    putchar(b31);
                    putchar(b32);
                }
            }
        }
        else if (count_byte >= 33 && count_byte <= 34) // block alignment
        {
            block_alignment += conv_hex_to_dec(reader);
            if (count_byte == 34)
            {
                bp1 = 0;
            }
            if (MODE == 2 || MODE == 3)
            {
                putchar(reader);
            }
        }
        else if (count_byte >= 35 && count_byte <= 36) // bits / sample
        {
            bits_sample += conv_hex_to_dec(reader);
            if (count_byte == 36)
            {
                bp1 = 0;
            }
            if (MODE == 2 || MODE == 3)
            {
                putchar(reader);
            }
        }
        else if (count_byte >= 37 && count_byte <= 40) // data
        {
            data += conv_hex_to_dec(reader);
            if (count_byte == 40)
            {
                bp1 = 0;
            }
            if (MODE == 2 || MODE == 3)
            {
                putchar(reader);
            }
        }
        else if (count_byte >= 41 && count_byte <= 44) // size of data chunk
        {
            size_of_data_chunk += conv_hex_to_dec(reader);
            if (count_byte == 44)
            {
                bp1 = 0;
            }
            if (MODE == 2 || MODE == 3)
            {
                putchar(reader);
            }
            if (MODE == 4 && count_byte == 44)
            {
                // Because in mode4 some variables change value , we have to write the file from the beginning and use the stored/read viriables and the new ones
                // after riff write size of file
                mode4_file_size = (size_of_file - size_of_data_chunk) + (size_of_data_chunk / 2);
                b5 = mode4_file_size & 255;
                b6 = (mode4_file_size >> 8) & 255;
                b7 = (mode4_file_size >> 16) & 255;
                b8 = (mode4_file_size >> 24) & 255;
                putchar(b5);
                putchar(b6);
                putchar(b7);
                putchar(b8);
                //after size of file write WAVE
                b9 = wave & 255;
                b10 = (wave >> 8) & 255;
                b11 = (wave >> 16) & 255;
                b12 = (wave >> 24) & 255;
                putchar(b9);
                putchar(b10);
                putchar(b11);
                putchar(b12);
                //after WAVE write fmt
                b13 = fmt & 255;
                b14 = (fmt >> 8) & 255;
                b15 = (fmt >> 16) & 255;
                b16 = (fmt >> 24) & 255;
                putchar(b13);
                putchar(b14);
                putchar(b15);
                putchar(b16);
                //after fmt write size of format chunck
                b17 = size_of_format_chunck & 255;
                b18 = (size_of_format_chunck >> 8) & 255;
                b19 = (size_of_format_chunck >> 16) & 255;
                b20 = (size_of_format_chunck >> 24) & 255;
                putchar(b17);
                putchar(b18);
                putchar(b19);
                putchar(b20);
                //after  size of format chunck write wave type format
                b21 = wave_type_format & 255;
                b22 = (wave_type_format >> 8) & 255;
                putchar(b21);
                putchar(b22);
                // after wave type format write mono/stereo
                mode4_mono_stereo = 1;
                b23 = mode4_mono_stereo & 255;
                b24 = (mode4_mono_stereo >> 8) & 255;
                putchar(b23);
                putchar(b24);
                //after mono write sample rate
                b25 = sample_rate & 255;
                b26 = (sample_rate >> 8) & 255;
                b27 = (sample_rate >> 16) & 255;
                b28 = (sample_rate >> 24) & 255;
                putchar(b25);
                putchar(b26);
                putchar(b27);
                putchar(b28);
                //after sample rate write bytes/sec
                mode4_bytes_sec = bytes_sec / 2;
                b29 = mode4_bytes_sec & 255;
                b30 = (mode4_bytes_sec >> 8) & 255;
                b31 = (mode4_bytes_sec >> 16) & 255;
                b32 = (mode4_bytes_sec >> 24) & 255;
                putchar(b29);
                putchar(b30);
                putchar(b31);
                putchar(b32);
                //after bytes/sec write block alignment
                mode4_block_align = block_alignment / 2;
                b33 = mode4_block_align & 255;
                b34 = (mode4_block_align >> 8) & 255;
                putchar(b33);
                putchar(b34);
                //after block alignment write bits/sample
                b35 = bits_sample & 255;
                b36 = (bits_sample >> 8) & 255;
                putchar(b35);
                putchar(b36);
                //after bits/sample write data
                b37 = data & 255;
                b38 = (data >> 8) & 255;
                b39 = (data >> 16) & 255;
                b40 = (data >> 24) & 255;
                putchar(b37);
                putchar(b38);
                putchar(b39);
                putchar(b40);
                //after data write size of data chunk
                mode4_size_data_chunk = size_of_data_chunk / 2;
                b41 = mode4_size_data_chunk & 255;
                b42 = (mode4_size_data_chunk >> 8) & 255;
                b43 = (mode4_size_data_chunk >> 16) & 255;
                b44 = (mode4_size_data_chunk >> 24) & 255;
                putchar(b41);
                putchar(b42);
                putchar(b43);
                putchar(b44);
            }
        }
        else if (count_byte >= 45 && count_byte <= 45 + size_of_data_chunk) // read from byte 45 where actual data is until the end of actual data
        {
            if (MODE == 4)
            {
                // Each block alignment needs seperate configuration
                if (block_alignment == 2)
                {
                    if (count_byte % 2 == 1)
                    {
                        putchar(reader);
                    }
                }
                else if (block_alignment == 4)
                {
                    if (count_byte == mode4_last && mode4_last % 2 == 1)
                    {
                        putchar(reader);
                        mode4_last += 1;
                    }
                    else if (count_byte == mode4_last && mode4_last % 2 == 0)
                    {
                        putchar(reader);
                        mode4_last += 3;
                    }
                }
            }
            else
            {
                if (MODE == 2 || MODE == 3)
                {
                    putchar(reader);
                }
            }
        }
        else
        {
            if (MODE != 1)
            {
                putchar(reader);
            }
        }

        count_byte++;
    }
    // Print out to the screen the varification of a wav file
    if (riff == 1179011410) // the decimal value of RIFF in ASCII is 1179011410
    {
        fprintf(stderr, "size of file: %lld\n", size_of_file);
        if (wave == 1163280727) // the decimal value of WAVE in ASCII is 1163280727
        {
            if (fmt == 544501094) // the decimal value of WAVE in ASCII is fmt is 544501094
            {
                fprintf(stderr, "size of format chunck: %lld\n", size_of_format_chunck);
                if (size_of_format_chunck == 16)
                {
                    fprintf(stderr, "WAVE type format: %lld\n", wave_type_format);
                    if (wave_type_format == 1)
                    {
                        fprintf(stderr, "mono/stereo: %lld\n", mono_stereo);
                        if (mono_stereo == 1 || mono_stereo == 2)
                        {
                            fprintf(stderr, "sample rate: %lld\n", sample_rate);
                            fprintf(stderr, "bytes/sec: %lld\n", bytes_sec);
                            fprintf(stderr, "block alignment: %lld\n", block_alignment);
                            if (sample_rate * block_alignment == bytes_sec)
                            {
                                fprintf(stderr, "bits/sample: %lld\n", bits_sample);
                                if (bits_sample == 8 || bits_sample == 16)
                                {
                                    if (bits_sample / 8 * mono_stereo == block_alignment)
                                    {
                                        if (data == 1635017060) //the decimal value of DATA in ASCII is 1635017060
                                        {
                                            fprintf(stderr, "size of data chunk: %lld\n", size_of_data_chunk);
                                            if (size_of_file_count - 8 >= size_of_file)
                                            {
                                                if (size_of_file_count - 8 != size_of_file)
                                                {
                                                    fprintf(stderr, "bad size file\n");
                                                }
                                            }
                                            else
                                            {
                                                fprintf(stderr, "insufficient data\n");
                                            }
                                        }
                                        else
                                        {
                                            fprintf(stderr, "Error! \"data\" not found\n");
                                        }
                                    }
                                    else
                                    {
                                        fprintf(stderr, "Error! block alignment should be bits per sample / 8 x mono/stereo\n");
                                    }
                                }
                                else
                                {
                                    fprintf(stderr, "Error! bits/sample should be 8 or 16\n");
                                }
                            }
                            else
                            {
                                fprintf(stderr, "Error! bytes/second should be sample rate x block alignment\n");
                            }
                        }
                        else
                        {
                            fprintf(stderr, "Error! mono/stereo should be 1 or 2\n");
                        }
                    }
                    else
                    {
                        fprintf(stderr, "Error! WAVE type format should be 1\n");
                    }
                }
                else
                {
                    fprintf(stderr, "Error! size of format chunck should be 16\n");
                }
            }
            else
            {
                fprintf(stderr, "Error! \"fmt \" not found\n");
            }
        }
        else
        {
            fprintf(stderr, "Error! \"WAVE\" not found\n");
        }
    }
    else
    {
        fprintf(stderr, "Error! \"RIFF\" not found\n");
    }
    return 0;
}

/*End of main*/
