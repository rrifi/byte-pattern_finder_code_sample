#include <Windows.h>
#include <iostream>
#include <algorithm>
#include <iomanip>

int main()
{


    BYTE Buffer[13] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFC, 0xAA, 0xBA }; //the buffer where you lookin for
    PBYTE pBufferLast = Buffer + sizeof(Buffer);
    
    BYTE Pattern[] = { 0xAA, 0xBA }; //the pattern
    PBYTE pPatternLast = Pattern + sizeof(Pattern);

    PBYTE pOccurrence = std::search(Buffer, pBufferLast, Pattern, pPatternLast);

    BOOL fFound = (pOccurrence != pBufferLast);


    if (fFound) {

        int* intArray = new int[sizeof(Pattern)];

        std::cout << "Pattern \"";
        for (int i = 0; i < sizeof(Pattern); ++i) {
            intArray[i] = Pattern[i];

            std::cout << std::uppercase << std::hex << "0x" << intArray[i];

            if (i != sizeof(Pattern) - 1) { std::cout << " "; }

        }
        std::cout << "\" ";
            
        std::cout << "found at position " << std::dec << pOccurrence - Buffer << std::endl;
        return 0;
        
        //Output : Pattern "0xAA 0xBA" found at position 11
    } 

    std::cout << "not found";


}
