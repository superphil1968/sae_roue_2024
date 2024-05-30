#include "bloc_io.h"
#include "mbed.h"
 
Bloc_IO::Bloc_IO(PinName RD_WRn,PinName CS,PinName __D0,PinName __D1,PinName __D2,PinName __D3,PinName __D4,PinName __D5,PinName __D6,PinName __D7) : _RD_WRn(RD_WRn), _CS(CS),Bloc_IoPort(__D0,__D1,__D2,__D3,__D4,__D5,__D6,__D7)  {
   
    _RD_WRn    = 1;// default read mode
    _CS=1;// default no selected
    
}
 
void Bloc_IO::write(unsigned char  byWrVal) {
    
     _CS=1;
     _RD_WRn=0; //Write Mode
     Bloc_IoPort.output();// set bus as output
    Bloc_IoPort.write((int)byWrVal);// update Bloc_Io port
     _CS=0;// enable write
     _CS=1;// disable write
     _RD_WRn=1;// read mode 
          
    
}

unsigned char Bloc_IO::read(void) {
   unsigned char byRedVal ;
     _CS=1;
     _RD_WRn=1; //Read Mode
     
      Bloc_IoPort.input(); // set bus as input
   
     _CS=0;// enable read
      byRedVal=(unsigned char) Bloc_IoPort.read();// update Bloc_Io port
     _CS=1;// disable read
     _RD_WRn=1;// read mode 
     return byRedVal;
}
      
    
