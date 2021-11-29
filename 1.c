//Logic
#define IIF(c) PRIMITIVE_CAT(IIF_, c)
#define IIF_0(t, ...) __VA_ARGS__
#define IIF_1(t, ...) t
#define COMPL(b) PRIMITIVE_CAT(COMPL_, b)
#define COMPL_0 1
#define COMPL_1 0
#define CHECK_N(x, n, ...) n
#define CHECK(...) CHECK_N(__VA_ARGS__, 0,)
#define PROBE(x) x, 1,
#define NOT(x) CHECK(PRIMITIVE_CAT(NOT_, x))
#define NOT_0 PROBE(~)
#define BOOL(x) COMPL(NOT(x))
#define IF(c) IIF(BOOL(c))
#define EAT(...)
#define EXPAND(...) __VA_ARGS__
#define EMPTY()
//Arithmetic for SimpleDecrement
#define DEC(x) PRIMITIVE_CAT(DEC_, x)
#define DEC_0 0
#define DEC_1 0
#define DEC_2 1
#define DEC_3 2
#define DEC_4 3
#define DEC_5 4
#define DEC_6 5
#define DEC_7 6
#define DEC_8 7
#define DEC_9 8
//Preprocessor trick for recursion
#define DEFER(id) id EMPTY()
#define OBSTRUCT(...) __VA_ARGS__ DEFER(EMPTY)()
#define EVAL(...)  EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL2(...) EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL3(...) EVAL4(EVAL4(EVAL4(__VA_ARGS__)))
#define EVAL4(...) EVAL5(EVAL5(EVAL5(__VA_ARGS__)))
#define EVAL5(...) __VA_ARGS__
//Helper
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
//Decrement with values up to 99999999
#define DECA_HELPER(...) IIF(NOT(BOOL(DEC(NUM_ARGS(__VA_ARGS__))))) (DECA(__VA_ARGS__,0),DECA(__VA_ARGS__))
#define DECA_INDIRECT() DECA
#define DECA(x, ...) PRIMITIVE_CAT(DECA_,x)(x,__VA_ARGS__)
#define DECA_0(_, ...) 9, OBSTRUCT(DECA_INDIRECT)()(__VA_ARGS__,0)
#define DECA_1(_, ...) 0,__VA_ARGS__
#define DECA_2(_, ...) 1,__VA_ARGS__
#define DECA_3(_, ...) 2,__VA_ARGS__
#define DECA_4(_, ...) 3,__VA_ARGS__
#define DECA_5(_, ...) 4,__VA_ARGS__
#define DECA_6(_, ...) 5,__VA_ARGS__
#define DECA_7(_, ...) 6,__VA_ARGS__
#define DECA_8(_, ...) 7,__VA_ARGS__
#define DECA_9(_, ...) 8,__VA_ARGS__
//Increment with values up to 9999999
#define INCA_HELPER(...) IIF(NOT(BOOL(DEC(NUM_ARGS(__VA_ARGS__))))) (INCA(__VA_ARGS__,0),INCA(__VA_ARGS__))
#define INCA(x, ...) PRIMITIVE_CAT(INCA_,x)(x,__VA_ARGS__)
#define EXPAND(...) __VA_ARGS__
#define WHEN(c) IF(c)(EXPAND, EAT)
#define INCA_(...) 1
#define INCA_0(_, ...) 1,__VA_ARGS__
#define INCA_1(_, ...) 2,__VA_ARGS__
#define INCA_2(_, ...) 3,__VA_ARGS__
#define INCA_3(_, ...) 4,__VA_ARGS__
#define INCA_4(_, ...) 5,__VA_ARGS__
#define INCA_5(_, ...) 6,__VA_ARGS__
#define INCA_6(_, ...) 7,__VA_ARGS__
#define INCA_7(_, ...) 8,__VA_ARGS__
#define INCA_8(_, ...) 9,__VA_ARGS__
#define INCA_9(_, ...) 0,OBSTRUCT(INCA_INDIRECT)()(__VA_ARGS__,0)
#define INCA_INDIRECT() INCA
//Output Logic for reversing comma seperated arguments, removing leading zeros, and concatenating whole lists.
#define PREP_FOR_OUTPUT(...) IIF(NOT(BOOL(DEC(NUM_ARGS(__VA_ARGS__))))) ((__VA_ARGS__),OBSTRUCT(REMOVE_LEADING_ZERO)(__VA_ARGS__))
#define REMOVE_LEADING_ZERO(x, ...) IIF(BOOL(x)) ((x,__VA_ARGS__),OBSTRUCT(REMOVE_LEADING_ZERO_INDIRECT)()(__VA_ARGS__))
#define REMOVE_LEADING_ZERO_INDIRECT() PREP_FOR_OUTPUT
#define REVERSE_1(a) a
#define REVERSE_2(a, b) OBSTRUCT(PRIMITIVE_CAT) (b,a)
#define REVERSE_3(a, ...) OBSTRUCT(PRIMITIVE_CAT) (EXPAND(REVERSE_2(__VA_ARGS__)),a)
#define REVERSE_4(a, ...) OBSTRUCT(PRIMITIVE_CAT) (EXPAND(REVERSE_3(__VA_ARGS__)),a)
#define REVERSE_5(a, ...) OBSTRUCT(PRIMITIVE_CAT) (EXPAND(REVERSE_4(__VA_ARGS__)),a)
#define REVERSE_6(a, ...) OBSTRUCT(PRIMITIVE_CAT) (EXPAND(REVERSE_5(__VA_ARGS__)),a)
#define REVERSE_7(a, ...) OBSTRUCT(PRIMITIVE_CAT) (EXPAND(REVERSE_6(__VA_ARGS__)),a)
#define REVERSE_8(a, ...) OBSTRUCT(PRIMITIVE_CAT) (EXPAND(REVERSE_7(__VA_ARGS__)),a)
#define REVERSE_9(a, ...) OBSTRUCT(PRIMITIVE_CAT) (EXPAND(REVERSE_8(__VA_ARGS__)),a)
#define REVERSE_10(a, ...) OBSTRUCT(PRIMITIVE_CAT) (EXPAND(REVERSE_9(__VA_ARGS__)),a)
#define REVERSE1(N, ...) EXPAND(REVERSE_ ## N(__VA_ARGS__))
#define REVERSE(N, ...) REVERSE1(N, __VA_ARGS__)
#define REVERSE_COMMA_1(a) a
#define REVERSE_COMMA_2(a, b) b,a
#define REVERSE_COMMA_3(a, ...) EXPAND(REVERSE_COMMA_2(__VA_ARGS__)),a
#define REVERSE_COMMA_4(a, ...) EXPAND(REVERSE_COMMA_3(__VA_ARGS__)),a
#define REVERSE_COMMA_5(a, ...) EXPAND(REVERSE_COMMA_4(__VA_ARGS__)),a
#define REVERSE_COMMA_6(a, ...) EXPAND(REVERSE_COMMA_5(__VA_ARGS__)),a
#define REVERSE_COMMA_7(a, ...) EXPAND(REVERSE_COMMA_6(__VA_ARGS__)),a
#define REVERSE_COMMA_8(a, ...) EXPAND(REVERSE_COMMA_7(__VA_ARGS__)),a
#define REVERSE_COMMA_9(a, ...) EXPAND(REVERSE_COMMA_8(__VA_ARGS__)),a
#define REVERSE_COMMA_10(a, ...) EXPAND(REVERSE_COMMA_9(__VA_ARGS__)),a
#define REVERSE_COMMA1(N, ...) EXPAND(REVERSE_COMMA_ ## N(__VA_ARGS__))
#define REVERSE_COMMA(N, ...) REVERSE_COMMA1(N, __VA_ARGS__)
#define _GET_NTH_ARG(_1, _2, _3, _4, _5, _6, _7, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, N, ...) N
#define NUM_ARGS(...) EXPAND(_GET_NTH_ARG(__VA_ARGS__,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0))
#define reverseStart REVERSE_COMMA(NUM_ARGS(start), start)
#define REPEAT_COMMA_INTEGER_INDIRECT() REPEAT_COMMA_INTEGER
#define COMMA_TO_NUMBER_INV(...) EVAL(REVERSE(NUM_ARGS(__VA_ARGS__),__VA_ARGS__))
//


//Complete Macros. One for incrementing/decrementing to a number. One for incrementing/decrementing to a list which can
// be further incremented / decremented.
#define dec_n(...) EVAL(REVERSE(NUM_ARGS(REVERSE_COMMA(NUM_ARGS(EVAL(EXPAND PREP_FOR_OUTPUT(REVERSE_COMMA(NUM_ARGS(EVAL(DECA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__),__VA_ARGS__)))), EVAL(DECA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__))))))), EVAL(EXPAND PREP_FOR_OUTPUT(REVERSE_COMMA(NUM_ARGS(EVAL(DECA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__),__VA_ARGS__)))), EVAL(DECA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__)))))))), REVERSE_COMMA(NUM_ARGS(EVAL(EXPAND PREP_FOR_OUTPUT(REVERSE_COMMA(NUM_ARGS(EVAL(DECA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__)))), EVAL(DECA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__))))))), EVAL(EXPAND PREP_FOR_OUTPUT(REVERSE_COMMA(NUM_ARGS(EVAL(DECA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__)))), EVAL(DECA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__)))))))))
#define inc_n(...) EVAL(REVERSE(NUM_ARGS(REVERSE_COMMA(NUM_ARGS(EVAL(EXPAND PREP_FOR_OUTPUT(REVERSE_COMMA(NUM_ARGS(EVAL(INCA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__),__VA_ARGS__)))), EVAL(INCA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__))))))), EVAL(EXPAND PREP_FOR_OUTPUT(REVERSE_COMMA(NUM_ARGS(EVAL(INCA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__),__VA_ARGS__)))), EVAL(INCA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__)))))))), REVERSE_COMMA(NUM_ARGS(EVAL(EXPAND PREP_FOR_OUTPUT(REVERSE_COMMA(NUM_ARGS(EVAL(INCA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__)))), EVAL(INCA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__))))))), EVAL(EXPAND PREP_FOR_OUTPUT(REVERSE_COMMA(NUM_ARGS(EVAL(INCA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__)))), EVAL(INCA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__)))))))))
#define INC_WITH_COMMA(...) EVAL(EXPAND PREP_FOR_OUTPUT(REVERSE_COMMA(NUM_ARGS(EVAL(INCA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__),__VA_ARGS__)))), EVAL(INCA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__))))))
#define DEC_WITH_COMMA(...) EVAL(EXPAND PREP_FOR_OUTPUT(REVERSE_COMMA(NUM_ARGS(EVAL(DECA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__),__VA_ARGS__)))), EVAL(DECA_HELPER(REVERSE_COMMA(NUM_ARGS(__VA_ARGS__), __VA_ARGS__))))))
//Making it beautiful
#define START int main() {
#define END return 0;}
#define EMPTYLINE printf("\n");
#define PR(i) printf("%d",i);
#include <stdio.h>
#define decrement_me 1,0,0,0
#define increment_me 9,9,9,9


START
    PR(dec_n(decrement_me))
    EMPTYLINE
    PR(inc_n(increment_me))
    EMPTYLINE
END
