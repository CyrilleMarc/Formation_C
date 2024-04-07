#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <time.h>

#include <common/common.h>

struct data
{
    char session[24];
    char filter[24];
    char session_id[30];
    char status[14];
    char reason[10];
    char server[20];
    char player[10];
    char game[30];
    char master_session[10];
    char multiplayer_mode[10];
    int execution_time;
    int start_at;
    int session_duration;
    char actions[10];
};

struct data backend_Gamestream;



int main(int argc, char* argv[])
{
    logger_set_current_level(LOG_INFO);
    logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);

    FILE* sourceFile = fopen("C:/Users/cyril/Desktop/dataFiles/Session_data.txt", "r");
    FILE* destinationFile = fopen("C:/Users/cyril/Desktop/dataFiles/Session_data_sorted2.csv", "w");
  

    if (NULL == sourceFile  || NULL == destinationFile )
    {
        logger_log(LOG_DEBUG, __FUNCSIG__, "File not found");
        return;
    }

 
    char line[1024]; 
    while (fgets(line, sizeof(line), sourceFile) != NULL)
    {
        sscanf(line, "%23s %23s %[^ ]9s %[^ ]13s %[^\n]9s %19s %9s %29s %9s %9s %d %d %d %9s",
            &backend_Gamestream.session, 
            backend_Gamestream.filter,
            backend_Gamestream.session_id,
            backend_Gamestream.status,
            backend_Gamestream.reason, 
            backend_Gamestream.server,
            backend_Gamestream.player, 
            backend_Gamestream.game,
            backend_Gamestream.master_session, 
            backend_Gamestream.multiplayer_mode,
            &backend_Gamestream.execution_time, 
            &backend_Gamestream.start_at,
            &backend_Gamestream.session_duration,
            backend_Gamestream.actions);

        fprintf(destinationFile, "%s,%s, %s, %s, %s, %s, %s, %s, %s, %s, %d, %d, %d, %s\n",
            backend_Gamestream.session, 
            backend_Gamestream.filter,
            backend_Gamestream.session_id, 
            backend_Gamestream.status,
            backend_Gamestream.reason, 
            backend_Gamestream.server,
            backend_Gamestream.player, 
            backend_Gamestream.game,
            backend_Gamestream.master_session, 
            backend_Gamestream.multiplayer_mode,
            backend_Gamestream.execution_time, 
            backend_Gamestream.start_at,
            backend_Gamestream.session_duration, 
            backend_Gamestream.actions);
    }
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
