ALL THESE LINK IN DESCRIPTION  
0. Download Game Code that Uses Allegro  

# [U-Byte]Blastoids_Git 
 U-Byte Version of The Classic Game Astroids Written in C and using Allegro Library.  
 https://github.com/Admin368/U-Byte_Blastoids
 
Allegro_MainSite: https://liballeg.org/  
Allegro_Documentation: https://www.allegro.cc/manual/5/  
Allegro_Github_Repository: https://github.com/liballeg/allegro5  
  

  
#QUICK INSTALL TO ALLEGRO with CodeBlocks  
1. Download Allegro 5.2.2  
   - https://github.com/liballeg/allegro5/releases/download/5.2.2.0/allegro-5.2.2.zip
  
2. Extract the Allegro Files To MinGW :
   - Copy "bin" , "inlcude" and "lib" folders  
   - Pase To your installation of MinGW.  
     - commonly its located in C:\MinGW  
     - or in you CodeBlocks Folder "C:\Program Files (x86)\CodeBlocks\MinGW".  
  
3. Add Linkers to your codeblocks Blastoids Project  
   - after making a project and the blastoids.c file to the project 
   - click "Project" on the top MenuBar  
   - select  "Build Options"<br/>
     - While onTheLeftSide "Blastoids" is selected  
         - onTheRightSide select "Linker Setting"  
         - select "Add" at the bottom  
         - click the folder icon to browse  
         - find location of your MinGW folder  
         - go in folder "lib"  
         - find file "liballegro_monolith-debug.dll.a"  
         - Eg. "C:\Program Files (x86)\CodeBlocks\MinGW\lib\liballegro_monolith-debug.dll.a"  
     - While onTheLeftSide "Build" is selected  
         - do the same as above step  
         - and find file "liballegro_monolith-debug.dll.a"  
     - While onTheLeftSide "Release" is selected  
         - do the same as above step  
         - and find file "liballegro_monolith.dll.a"  
 
 YOU ARE DONE, YOU CAN TEST BUILD THE PROJECT.  

