#ifndef BLOC_IO_H
#define BLOC_IO_H

#include "mbed.h"


/** bloc_io class.
 *  Used for exchange byte with altera 7064 PLD.
 *
 * Example:
 * @code
 * #include "mbed.h"
 * #include "bloc_io.h"
 *
 * Bloc_IO My_PLD (pin RD_WRn,pin CS, pin D0......,pin D7);
 * unsigned char byVal; 
 * 
 * int main() {
 *     My_PLD.write (byVal);// send byte from Mbed to PLD
*      byVal=My_PLD.read();// read byre from PLD to Mbed 
 * }
 * @endcode
 */
 
class Bloc_IO {
public:
 /** Bloc_IO construct
         *
         * @param RD_WRn pin reserved for R/W control signal  on mbed
         * @param CS pin reserved for chip select control signal  on mbed
         * @param __D0 pin reserved for lsb on Mbed data bus
         * @param __D7 pin reserved for msb on Mbed data bus
         * @returns
         *  no return
         */
    Bloc_IO(PinName RD_WRn,PinName CS,PinName __D0,PinName __D1,PinName __D2,PinName __D3,PinName __D4,PinName __D5,PinName __D6,PinName __D7);
    
    /**  read byte method
         * @param : no parameter
         * @returns
         * byte red from PLD
         */
    unsigned char read(void);
    
    /**  write byte method
         *@param byWrVal: byte to write to PLD
         * @returns
         *  no returns
         */
    void write (unsigned char byWrVal);
  
  
private:  
    DigitalOut _RD_WRn;
    DigitalOut _CS;
    BusInOut Bloc_IoPort; 
  
    
   
};


  #endif
