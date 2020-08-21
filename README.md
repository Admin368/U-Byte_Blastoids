# [U-Byte]Blastoids_Git  
 U-Byte Version of The Classic Game Astroids using Allegro  
  
#QUICK INSTALL TO ALLEGRO with CodeBlocks  
1.Download Allegro 5.2.2  
  
2.Extract the Files and copy the following:  
"bin" , "inlcude" and "lib" folders  
-To your installation of MinGW.  
-commonly its located in C:\MinGW  
-or in you CodeBlocks Folder "C:\Program Files (x86)\CodeBlocks\MinGW".  
  
3.Add Linkers to your codeblocks Blastoids Project  
-after making a project and the blastoids.c file to the project 
-click "Project" on the top MenuBar  
-select  "Build Options"  
  -While onTheLeftSide "Blastoids" is selected  
      - onTheRightSide select "Linker Setting"  
      - select "Add" at the bottom  
      - click the folder icon to browse  
      - find location of your MinGW folder  
      - go in folder "lib"  
      - find file "liballegro_monolith-debug.dll.a"  
      - Eg. "C:\Program Files (x86)\CodeBlocks\MinGW\lib\liballegro_monolith-debug.dll.a"  
-While onTheLeftSide "Build" is selected  
      - do the same as above step  
      - and find file "liballegro_monolith-debug.dll.a"  
-While onTheLeftSide "Release" is selected  
      - do the same as above step  
      - and find file "liballegro_monolith.dll.a"  
  
YOU ARE DONE, YOU CAN TEST BUILD THE PROJECT.  

