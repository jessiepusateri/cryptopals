#include "ciph.h"
/*
float char_val(char c) {
	switch (c) {
	case ' ': return 10;
	case 'a': return 8.167;
	case 'b': return 1.492;
	case 'c': return 2.782;
	case 'd': return 4.253;
	case 'e': return 12.702;
	case 'f': return 2.228;
	case 'g': return 2.015;
	case 'h': return 6.094;
	case 'i': return 6.966;
	case 'j': return 0.153;
	case 'k': return 0.772;
	case 'l': return 4.025;
	case 'm': return 2.406;
	case 'n': return 6.749;
	case 'o': return 7.507;
	case 'p': return 1.929;
	case 'q': return 0.095;
	case 'r': return 5.987;
	case 's': return 6.327;
	case 't': return  9.056;
	case 'u': return 2.758;
	case 'v': return 0.978;
	case 'w': return 2.360;
	case 'x': return 0.150;
	case 'y': return 1.974;
	case 'z': return 0.074;
	default: return 0;
	}
}
*/


float char_val(char c) {
	switch (c) {
	case 9: 0.0057;
	case 32: return 17.1662;
	case 33: return 0.0072;
	case 34: return  0.2442;
	case 35: return 0.0179;
	case 36: return 0.0561;
	case 37: return 0.0160;
	case 38: return 0.0226;
	case 39: return  0.2447;
	case 40: return 0.2178;
	case 41: return 0.2233;
	case 42: return 0.0628;
	case 43: return 0.0215;
	case 44: return 0.7384;
	case 45: return 1.3734;
	case 46: return 1.5124;
	case 47: return 0.1549;
	case 48: return 0.5516;
	case 49: return 0.4594;
	case 50: return 0.3322;
	case 51: return 0.1847;
	case 52: return 0.1348;
	case 53: return 0.1663;
	case 54: return 0.1153;
	case 55: return 0.1030;
	case 56: return 0.1054;
	case 57: return 0.1024;
	case 58: return 0.4354;
	case 59: return 0.1214;
	case 60: return 0.1225;
	case 61: return 0.0227;
	case 62: return 0.1242;
	case 63: return 0.1474;
	case 64: return 0.0073;
	case 65: return 0.3132;
	case 66: return 0.2163;
	case 67: return 0.3906;
	case 68: return 0.3151;
	case 69: return 0.2673;
	case 70: return 0.1416;
	case 71: return 0.1876;
	case 72: return 0.2321;
	case 73: return 0.3211;
	case 74: return 0.1726;
	case 75: return 0.0687;
	case 76: return 0.1884;
	case 77: return 0.3529;
	case 78: return 0.2085;
	case 79: return 0.1842;
	case 80: return 0.2614;
	case 81: return 0.0316;
	case 82: return 0.2519;
	case 83: return 0.4003;
	case 84: return 0.3322;
	case 85: return 0.0814;
	case 86: return 0.0892;
	case 87: return 0.2527;
	case 88: return 0.0343;
	case 89: return 0.0304;
	case 90: return 0.0076;
	case 91: return 0.0086;
	case 92: return 0.0016;
	case 93: return 0.0088;
	case 94: return 0.0003;
	case 95: return 0.1159;
	case 96: return 0.0009;
	case 97: return 5.1880;
	case 98: return 1.0195;
	case 99: return 2.1129;
	case 100: return 2.5071;
	case 101: return 8.5771;
	case 102: return 1.3725;
	case 103: return 1.5597;
	case 104: return 2.7444;
	case 105: return 4.9019;
	case 106: return 0.0867;
	case 107: return 0.6753;
	case 108: return 3.1750;
	case 109: return 1.6437;
	case 110: return 4.9701;
	case 111: return 5.7701;
	case 112: return 1.5482;
	case 113: return 0.0747;
	case 114: return 4.2586;
	case 115: return 4.3686;
	case 116: return 6.3700;
	case 117: return 2.0999;
	case 118: return 0.8462;
	case 119: return 1.3034;
	case 120: return 0.1950;
	case 121: return 1.1330;
	case 122: return 0.0596;
	case 123: return 0.0026;
	case 124: return 0.0007;
	case 125: return 0.0026;
	case 126: return 0.0003;
	case 149: return 0.6410;
	case 183: return 0.0010;
	default: return 0;
	}
}










/*

float char_val(char c) {
	switch (c) {
	case 'a': return 7.52766;
	case 'e': return 7.0925;
	case 'o': return  5.17;
	case 'r': return 4.96032;
	case 'i': return 4.69732;
	case 's': return 4.61079;
	case 'n': return 4.56899;
	case '1': return 4.35053;
	case 't': return 3.87388;
	case 'l': return 3.77728;
	case '2': return 3.12312;
	case 'm': return 2.99913;
	case 'd': return 2.76401;
	case '0': return 2.74381;
	case 'c': return 2.57276;
	case 'p': return 2.45578;
	case '3': return 2.43339;
	case 'h': return 2.41319;
	case 'b': return 2.29145;
	case 'u': return 2.10191;
	case 'k': return 1.96828;
	case '4': return 1.94265;
	case '5': return 1.88577;
	case 'g': return 1.85331;
	case '9': return 1.79558;
	case '6': return 1.75647;
	case '8': return 1.66225;
	case '7': return 1.621;
	case 'y': return 1.52483;
	case 'f': return 1.2476;
	case 'w': return 1.24492;
	case 'j': return 0.836677;
	case 'v': return 0.833626;
	case 'z': return 0.632558;
	case 'x': return 0.573305;
	case 'q': return 0.346119;
	case 'A': return 0.130466;
	case 'S': return 0.108132;
	case 'E': return 0.0970865;
	case 'R': return 0.08476;
	case 'B': return 0.0806715;
	case 'T': return 0.0801223;
	case 'M': return 0.0782306;
	case 'L': return 0.0775594;
	case 'N': return 0.0748134;
	case 'P': return 0.073715;
	case 'O': return 0.0729217;
	case 'I': return 0.070908;
	case 'D': return 0.0698096;
	case 'C': return 0.0660872;
	case 'H': return 0.0544319;
	case 'G': return 0.0497332;
	case 'K': return 0.0460719;
	case 'F': return 0.0417393;
	case 'J': return 0.0363083;
	case 'U': return 0.0350268;
	case 'W': return 0.0320367;
	case '.': return 0.0316706;
	case '!': return 0.0306942;
	case 'Y': return 0.0255073;
	case '*': return 0.0241648;
	case '@': return 0.0238597;
	case 'V': return 0.0235546;
	case '-': return 0.0197712;
	case 'Z': return 0.0170252;
	case 'Q': return 0.0147064;
	case 'X': return 0.0142182;
	case '_': return 0.0122655;
	case '$': return 0.00970255;
	case '#': return 0.00854313;
	case ',': return 0.00323418;
	case '/': return 0.00311214;
	case '+': return 0.00231885;
	case '?': return 0.00207476;
	case ';': return 0.00207476;
	case '^': return 0.00195272;
	case ' ': return 0.00189169;
	case '%': return 0.00170863;
	case '~': return 0.00152556;
	case '=': return 0.00140351;
	case '&': return 0.00134249;
	case '`': return 0.00115942;
	case '\\': return 0.00115942;
	case ')': return 0.00115942;
	case ']': return 0.0010984;
	case '[': return 0.0010984;
	case ':': return 0.000549201;
	case '<': return 0.000427156;
	case '(': return 0.000427156;
	case '>': return 0.000183067;
	case '"': return 0.000183067;
	case '|': return 0.000122045;
	case '{': return 0.000122045;
	case '\'': 0.000122045;
	default: return 0;
	}
}*/