#include <Process.h>
#include "http.h"

void initHttp()
{
  Bridge.begin();
}

char buffer[512] = {0};
char* httpGet()
{
  return buffer;
}
