#include <stdio.h>
#include <iostream>

/**
 * Convert human readable IPv4 address to UINT32
 * @param pDottedQuad   Input C string e.g. "192.168.0.1"
 * @param pIpAddr       Output IP address as UINT32
 * return 1 on success, else 0
 */
int ipStringToNumber (const char*       pDottedQuad,
                              unsigned int *    pIpAddr);
int main(){
	unsigned int* ip;
	const char* ch = "192.168.0.1";
	ipStringToNumber(ch, ip);
	std::cout << ip << std::endl;
	return 0;
}
int ipStringToNumber (const char*       pDottedQuad,
                              unsigned int *    pIpAddr)
{
   unsigned int            byte3;
   unsigned int            byte2;
   unsigned int            byte1;
   unsigned int            byte0;
   char              dummyString[2];

   /* The dummy string with specifier %1s searches for a non-whitespace char
    * after the last number. If it is found, the result of sscanf will be 5
    * instead of 4, indicating an erroneous format of the ip-address.
    */
   if (sscanf (pDottedQuad, "%u.%u.%u.%u%1s",
                  &byte3, &byte2, &byte1, &byte0, dummyString) == 4)
   {
      if (    (byte3 < 256)
           && (byte2 < 256)
           && (byte1 < 256)
           && (byte0 < 256)
         )
      {
         *pIpAddr  =   (byte3 << 24)
                     + (byte2 << 16)
                     + (byte1 << 8)
                     +  byte0;

         return 1;
      }
   }

   return 0;
}