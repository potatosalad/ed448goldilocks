// FIXME move to arch or something
#define WBITS DECAF_WORD_BITS

#if WBITS == 64
#define LBITS 56
typedef __int128_t decaf_sdword_t;
#define LIMB(x) (x##ull)
#define SC_LIMB(x) (x##ull)
#elif WBITS == 32
typedef int64_t decaf_sdword_t;
#define LBITS 28
#define LIMB(x) (x##ull)&((1ull<<LBITS)-1), (x##ull)>>LBITS
#define SC_LIMB(x) (x##ull)&((1ull<<32)-1), (x##ull)>>32
#else
#error "Only supporting 32- and 64-bit platforms right now"
#endif

#define API_NAME "decaf_448"
#define API_NS(_id) decaf_448_##_id
#define API_NS2(_pref,_id) _pref##_decaf_448_##_id

#define SCALAR_LIMBS DECAF_448_SCALAR_LIMBS
#define SCALAR_BITS DECAF_448_SCALAR_BITS
#define NLIMBS DECAF_448_LIMBS
#define scalar_t decaf_448_scalar_t
#define point_t decaf_448_point_t
#define precomputed_s decaf_448_precomputed_s
#define SER_BYTES DECAF_448_SER_BYTES
#define IMAGINE_TWIST 0
#define P_MOD_8 7
#define COFACTOR 4

static const int EDWARDS_D = -39081;

static const scalar_t sc_p = {{{
    SC_LIMB(0x2378c292ab5844f3),
    SC_LIMB(0x216cc2728dc58f55),
    SC_LIMB(0xc44edb49aed63690),
    SC_LIMB(0xffffffff7cca23e9),
    SC_LIMB(0xffffffffffffffff),
    SC_LIMB(0xffffffffffffffff),
    SC_LIMB(0x3fffffffffffffff)
}}};

#ifdef GEN_TABLES
/* sqrt(5) = 2phi-1 from the curve spec.  Not exported, but used by pregen tool. */
static const unsigned char base_point_ser_for_pregen[SER_BYTES] = {
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1
};
#endif
