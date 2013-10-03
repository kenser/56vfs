#ifndef __VFS_SIG_SO_H
#define __VFS_SIG_SO_H
#include "list.h"
#include "global.h"
#include "vfs_init.h"
#include "vfs_task.h"
#include "common.h"
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>
#include <stropts.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <dirent.h>

#define SELF_ROLE ROLE_CS

enum SOCK_STAT {LOGOUT = 0, CONNECTED, LOGIN, IDLE, PREPARE_RECVFILE, RECVFILEING, SENDFILEING, LAST_STAT};

extern const char *sock_stat_cmd[] ;

typedef struct {
	list_head_t alist;
	list_head_t hlist;
	int fd;
	int local_in_fd; /* ��cs���ܶԶ��ļ�����ʱ���򿪵ı��ؾ�� ��fd�ɲ���Լ����� */
	uint32_t hbtime;
	uint32_t ip;
	uint32_t headlen; /*��ǰ�����ļ���ͷ��Ϣ����*/
	uint8_t role;  /*FCS, CS, TRACKER */
	uint8_t sock_stat;   /* SOCK_STAT */
	uint8_t server_stat; /* server stat*/
	uint8_t mode;  /* active , passive */
	t_vfs_tasklist *recvtask; /*��ǰ������·����ִ�е����ݽ������� */
	t_vfs_tasklist *sendtask; /*��ǰ������·����ִ�е����ݴ������� */
} vfs_cs_peer;

typedef struct {
	char username[64];
	char password[64];
	char host[32];
	int port;
} t_vfs_up_proxy;

#endif