#include "Leadwerks.h"
 
namespace Leadwerks
{
    void GetPassword(String& s)
    {
        s.resize(64);
        auto buffer = CreateStaticBuffer(s.Data(), s.size());
		buffer->PokeByte(4, 'G');
		buffer->PokeByte(7, 'R');
		buffer->PokeByte(41, 'D');
		buffer->PokeByte(28, '{');
		buffer->PokeByte(14, 'i');
		buffer->PokeByte(21, '=');
		buffer->PokeByte(63, '&');
		buffer->PokeByte(45, '|');
		buffer->PokeByte(36, 'Z');
		buffer->PokeByte(16, 'G');
		buffer->PokeByte(55, 'M');
		buffer->PokeByte(12, '[');
		buffer->PokeByte(19, 'E');
		buffer->PokeByte(48, 'F');
		buffer->PokeByte(62, 'E');
		buffer->PokeByte(15, '^');
		buffer->PokeByte(44, '}');
		buffer->PokeByte(37, 'L');
		buffer->PokeByte(43, 'B');
		buffer->PokeByte(31, ',');
		buffer->PokeByte(30, 'x');
		buffer->PokeByte(32, '&');
		buffer->PokeByte(54, '7');
		buffer->PokeByte(40, '0');
		buffer->PokeByte(53, ')');
		buffer->PokeByte(29, 'q');
		buffer->PokeByte(1, '}');
		buffer->PokeByte(46, 'X');
		buffer->PokeByte(33, 'L');
		buffer->PokeByte(57, 'd');
		buffer->PokeByte(17, 'c');
		buffer->PokeByte(22, 'p');
		buffer->PokeByte(20, 'y');
		buffer->PokeByte(34, 'K');
		buffer->PokeByte(11, '{');
		buffer->PokeByte(38, '!');
		buffer->PokeByte(26, 'Y');
		buffer->PokeByte(59, '3');
		buffer->PokeByte(58, 'B');
		buffer->PokeByte(49, 'c');
		buffer->PokeByte(27, 'X');
		buffer->PokeByte(61, 'b');
		buffer->PokeByte(35, 'D');
		buffer->PokeByte(52, 'g');
		buffer->PokeByte(3, 'a');
		buffer->PokeByte(9, 'I');
		buffer->PokeByte(13, 'v');
		buffer->PokeByte(8, 'z');
		buffer->PokeByte(24, 'H');
		buffer->PokeByte(10, '9');
		buffer->PokeByte(18, '[');
		buffer->PokeByte(25, 'L');
		buffer->PokeByte(56, 'n');
		buffer->PokeByte(5, 'W');
		buffer->PokeByte(42, '!');
		buffer->PokeByte(47, '5');
		buffer->PokeByte(2, 'S');
		buffer->PokeByte(50, '@');
		buffer->PokeByte(0, ')');
		buffer->PokeByte(6, '2');
		buffer->PokeByte(39, 'c');
		buffer->PokeByte(51, '(');
		buffer->PokeByte(23, '6');
		buffer->PokeByte(60, 'C');

#ifdef _DEBUG
        //Only uncomment this for testing
        //Assert(s == ")}SaGW2RzI9{[vi^Gc[Ey=p6HLYX{qx,&LKDZL!c0D!B}|X5Fc@(g)7MndB3CbE&");
#endif
    }
}