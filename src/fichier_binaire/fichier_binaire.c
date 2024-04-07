#include <stdio.h>
#include <stdlib.h>

#include <common/common.h>

int store_binary_file(const char *fileName, const char *content, int element_count) {
	FILE* file = fopen(fileName, "wb");
	if (NULL == file)
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "File not found");
		return -1;
	}
	size_t write_count = fwrite(content, sizeof(char), element_count, file);
	if (write_count != element_count) {
		logger_log(LOG_DEBUG, __FUNCSIG__, "Failed to write to file");
		return -1;
	}

	fclose(file);

	return 0;
}

int display_binary_data_in_file(const char *fileName, const char *content, int element_count)
{
	FILE* file = fopen(fileName, "rb");

	size_t fileIsRead = fread(content, sizeof(char), element_count, file);
	if (fileIsRead != element_count)
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "Failed to read the file");
		return -1;
	}
	return 0;
}