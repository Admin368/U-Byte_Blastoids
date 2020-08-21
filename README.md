ALL THE LINKS IN DESCRIPTION  

# [U-Byte]Blastoids_Git 
 U-Byte Version of The Classic Game Astroids Written in C and using Allegro Library.  
 https://github.com/Admin368/U-Byte_Blastoids
 
Allegro_MainSite: https://liballeg.org/  
Allegro_Documentation: https://www.allegro.cc/manual/5/  
Allegro_Github_Repository: https://github.com/liballeg/allegro5  
  

  
#QUICK INSTALL TO ALLEGRO with CodeBlocks  
Video Of how to Configure https://youtu.be/pOfta63vDX4  
1. Download Allegro 5.2.2  
   - https://www.allegro.cc/files/
   - direct_Link: http://cdn.allegro.cc/file/library/allegro/5.0.10/allegro-5.0.10-mingw-4.5.0.zip
  
2. Extract the Allegro Files To MinGW :
   - Copy "bin" , "inclde" and "lib" folders  
   - Paste To your installation of MinGW.  
     - Commonly its located in C:\MinGW  
     - Or in you CodeBlocks Folder "C:\Program Files (x86)\CodeBlocks\MinGW".  
  
3. Add Linkers to your codeblocks Blastoids Project  
   - Extract The Game files
   - Make a fresh CodeBlock Project in the Game files folder
   - after making the project add the blastoids.c file to the project 
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
     - While onTheLeftSide "Debug" is selected  
         - do the same as above step  
         - and find file "liballegro_monolith-debug.dll.a"  
     - While onTheLeftSide "Release" is selected  
         - do the same as above step  
         - and find file "liballegro_monolith.dll.a" 
         
MAKE SURE ALL GAME FILES ARE IN CODE BLOCKS PROJECT FOLDER!  
YOU ARE DONE, YOU CAN TEST BUILD THE PROJECT.    

