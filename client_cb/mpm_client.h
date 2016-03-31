/* common structures */
#define mpm_is_objet_precieux(x)              (MPM_ARME <= (x) && (x) <= MPM_BONUS)
#define MPM_TYPE_OBJET_PRECIEUX(x)            ((x) - MPM_ARME)
#define MPM_CARD_TYPE_OBJET_PRECIEUX          (MPM_TYPE_OBJET_PRECIEUX(MPM_BONUS) + 1)

#define MPM_MAX_ARME_PAR_PION                 4
#define MPM_MAX_POUVOIR_DESARMEMENT_PAR_PION  2
#define MPM_MAX_POUVOIR_OBSTACLE_PAR_CLIENT   2
#define MPM_MAX_BONUS                        -1
#define MPM_MAX_OBJET_PRECIEUX_PAR_PION       4


/* Terrain */

#define MPM_NB_COLONNES  20
#define MPM_NB_LIGNES    20
#define MPM_LARGEUR_ZONE 30 /* Cellule: 30 px */

typedef enum _mpm_type_objet_t {
	MPM_VOIE,
	MPM_JOUEUR1_PION1,
	MPM_JOUEUR1_PION2,
	MPM_JOUEUR2_PION1,
	MPM_JOUEUR2_PION2,
	MPM_ARME,
	MPM_POUVOIR_DESARMEMENT,
	MPM_POUVOIR_OBSTACLE,
	MPM_BONUS,
	MPM_MUR
} mpm_type_objet_t;


/* Pions */

typedef enum _mpm_etat_pion_t {
	MPM_PION_DESARME,
	MPM_PION_ARME,
	MPM_PION_PROTEGE,
	MPM_PION_TRIOMPHANT,
	MPM_PION_MORT,
	MPM_PION_ETAT_COURANT
} mpm_etat_pion_t;


typedef struct _reserve_objet_precieux_t {
	int val;
	int offset_x;
	int offset_y;
} reserve_objet_precieux_t;

/* lite structures for the client */


typedef struct _reserve_objet_precieux_v2_t {
	int val;
} reserve_objet_precieux_v2_t;

typedef struct _mpm_pion_t_lite {
	/* Etat */
	COORD                          pos;
	COORD                          ancienne_pos;
	mpm_etat_pion_t                etat;
	reserve_objet_precieux_v2_t    reserve[MPM_CARD_TYPE_OBJET_PRECIEUX];
	int                            derniere_activation[MPM_CARD_TYPE_OBJET_PRECIEUX - 1];
} mpm_pion_t_lite;

typedef struct _mpm_joueur_t_lite {
	mpm_pion_t_lite pion[2];
} mpm_joueur_t_lite;

typedef struct _mpm_t_lite {
	mpm_joueur_t_lite joueur[2];
} mpm_t_lite;

