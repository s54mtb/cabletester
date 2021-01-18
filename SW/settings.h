


#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#define MODE_NORMAL  0
#define MODE_FAST    1


typedef struct {
	uint16_t enabled;  /* channel enabled */
	uint8_t  mode;     /* 0 = normal, 1 = fast */  
} settings_t;


void CheckSettings(void);

#endif

