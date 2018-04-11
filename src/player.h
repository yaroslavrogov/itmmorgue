// vim: sw=4 ts=4 et :
#ifndef PLAYER_H
#define PLAYER_H

#include "itmmorgue.h"
#include "entity.h"

#define MAX_PLAYERS 5

// typedef struct player {
//     enum colors color;          // server-specified attributes
//     uint16_t y;                 // absolute Y
//     uint16_t x;                 // absolute X
//     char nickname[PLAYER_NAME_MAXLEN];
//     uint8_t ready;              // ready for the game
//     uint8_t connected;          // connected to the server
//     // I hate that global variable, but I don't have time to fix it
//     uint8_t start;              // needs data renewal
//     connection_t *connection;
//     event_queue_t ev_queue;
//     /* inventory_t */
//     /* common creatures stats_t */
//     /* player specific stats ?? */
//     /* spell_list_t */
//     /* skills_t */
// } player_t;

typedef struct players_full_mbuf {
    player_t players[MAX_PLAYERS];
    uint8_t self;
    size_t players_len;
} players_full_mbuf_t;

typedef struct players_mbuf {
    struct c_player {
        enum colors color;
        uint16_t y;
        uint16_t x;
    } players[MAX_PLAYERS];
    uint8_t self;
    size_t players_len;
} players_mbuf_t;

typedef struct player_move {
    enum keyboard direction;
    size_t player_id;
} player_move_t;

size_t player_init(enum colors color, char *nickname,
        connection_t *connection);
void c_receive_players(players_mbuf_t *mbuf);
void c_receive_players_full(players_full_mbuf_t *mbuf);
void s_send_players_full(player_t *player);
void s_send_players(player_t *player);
void c_send_move(enum keyboard last_key);

// extern player_t players[];
extern entity_t* players2[];
extern size_t players_len;
extern size_t player_self;
extern size_t players_total;

#endif /* PLAYER_H */
