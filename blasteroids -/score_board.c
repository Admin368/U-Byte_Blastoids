#include "header_global.h"

typedef struct playerScore
{
    char badge[26]; // S,Mr,T,Mk
    int rank;
    char name[26];
    unsigned long int highestScore;
    char playTime[13]; //00:00:00:00
}playerScore;


void generateScoreBoard()
{
    int tableLength = DISP_W*0.75;
    float startX,startY,endX,endY;
    float cellHeight;
    float cellWidth;
    int i;
    float height;

    int totalScores = 17;
    playerScore scoresArray[17] ={
        {"Mk",8,"BenTen10",859600,"00:42:01:88"},
        {"S",3,"Kunta Kinte",1552,"00:20:01:20"},
        {"Mk",8,"BenTen10",859600,"00:42:01:88"},
        {"S",3,"Kunta Kinte",1552,"00:20:01:20"},
        {"Mk",8,"BenTen10",859600,"00:42:01:88"},
        {"S",3,"Kunta Kinte",1552,"00:20:01:20"},
        {"Mk",8,"BenTen10",859600,"00:42:01:88"},
        {"S",3,"Kunta Kinte",1552,"00:20:01:20"},
        {"Mk",8,"BenTen10",859600,"00:42:01:88"},
        {"S",3,"Kunta Kinte",1552,"00:20:01:20"},
        {"Mk",8,"BenTen10",859600,"00:42:01:88"},
        {"S",3,"Kunta Kinte",1552,"00:20:01:20"},
        {"Mk",8,"BenTen10",859600,"00:42:01:88"},
        {"S",3,"Kunta Kinte",1552,"00:20:01:20"},
        {"Mk",8,"BenTen10",859600,"00:42:01:88"},
        {"S",3,"Kunta Kinte",1552,"00:20:01:20"},
        {"Mr",8,"Uncle",9000,"00:23:27:03"}};

    al_draw_text(fontStartTitle, al_map_rgb(textColor),DISP_W*0.5,DISP_H*0.02,
                                  ALLEGRO_ALIGN_CENTRE, "Score Board");

    height = DISP_H*0.1;
    startX = DISP_W*0.125; endX = startX+tableLength;
    startY = height; endY = startY;
    al_draw_line(startX,startY,endX,endY,al_map_rgb(0,0,0), 1);


    /*draw header dividers*/
    char rowData[5][26];
    for (i = 0; i < totalScores + 1; i++)
    {
        memset(rowData,0,sizeof(rowData));
        if(i == 0)
        {
            strcpy(rowData[0],"Badge");
            strcpy(rowData[1],"Rank");
            strcpy(rowData[2],"Player Name");
            strcpy(rowData[3],"Highest Score");
            strcpy(rowData[4],"Play Time");
        }else
        {
            strcpy(rowData[0],scoresArray[i-1].badge);
            strcpy(rowData[1],itoa(scoresArray[i-1].rank,rowData[1],10));
            strcpy(rowData[2],scoresArray[i-1].name);
            strcpy(rowData[3],itoa(scoresArray[i-1].highestScore,rowData[3],10));
            strcpy(rowData[4],scoresArray[i-1].playTime);
        }

        cellHeight = 30.0;
        cellWidth = tableLength/5.0;
        startX = DISP_W*0.125; endX = startX;
        startY = height; endY = startY + cellHeight;
        al_draw_line(startX,startY,endX,endY,al_map_rgb(0,0,0), 1);
        al_draw_text(fontSmall, al_map_rgb(textColor),startX + (cellWidth-strlen(rowData[0]))/2,startY+cellHeight/2.5,
                                  ALLEGRO_ALIGN_CENTRE, rowData[0]);

        startX = DISP_W*0.125 + cellWidth; endX = startX;
        startY = height; endY = startY + cellHeight;
        al_draw_line(startX,startY,endX,endY,al_map_rgb(0,0,0), 1);
        al_draw_text(fontSmall, al_map_rgb(textColor),startX + (cellWidth-strlen(rowData[1]))/2,startY+cellHeight/2.5,
                                  ALLEGRO_ALIGN_CENTRE, rowData[1]);

        startX = startX + cellWidth; endX = startX;
        al_draw_line(startX,startY,endX,endY,al_map_rgb(0,0,0), 1);
        al_draw_text(fontSmall, al_map_rgb(textColor),startX + (cellWidth-strlen(rowData[2]))/2,startY+cellHeight/2.5,
                                  ALLEGRO_ALIGN_CENTRE, rowData[2]);

        startX = startX + cellWidth; endX = startX;
        al_draw_line(startX,startY,endX,endY,al_map_rgb(0,0,0), 1);
        al_draw_text(fontSmall, al_map_rgb(textColor),startX + (cellWidth-strlen(rowData[3]))/2,startY+cellHeight/2.5,
                                  ALLEGRO_ALIGN_CENTRE, rowData[3]);

        startX = startX + cellWidth; endX = startX;
        al_draw_line(startX,startY,endX,endY,al_map_rgb(0,0,0), 1);
        al_draw_text(fontSmall, al_map_rgb(textColor),startX + (cellWidth-strlen(rowData[4]))/2,startY+cellHeight/2.5,
                                  ALLEGRO_ALIGN_CENTRE, rowData[4]);

        /*--draw header dividers up --*/

        startX = DISP_W*0.125; endX = startX+tableLength;
        startY = height+cellHeight; endY = startY;
        al_draw_line(startX,startY,endX,endY,al_map_rgb(0,0,0), 1);

        cellHeight = 30.0;
        startX = DISP_W*0.125 + tableLength; endX = startX;
        startY = height; endY = startY + cellHeight;
        al_draw_line(startX,startY,endX,endY,al_map_rgb(0,0,0), 1);

        height = height + cellHeight; //next row
    }

}
