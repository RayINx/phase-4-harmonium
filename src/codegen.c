#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tree.h>
#include <strtab.h>

#define PROGRAM 0
#define DECLLIST 1
#define DECL 2
#define VARDECL 3
#define TYPESPECIFIER 4
#define FUNDECL 5
#define FORMALDECLLIST 6
#define FORMALDECL 7
#define FUNBODY 8
#define LOCALDECLLIST 9
#define STATEMENTLIST 10
#define STATEMENT 11
#define COMPOUNDSTMT 12
#define ASSIGNSTMT 13
#define CONDSTMT 14
#define LOOPSTMT 15
#define RETURNSTMT 16
#define EXPRESSION 17
#define RELOP 18
#define ADDEXPR 19
#define ADDOP 20
#define TERM 21
#define MULOP 22
#define FACTOR 23
#define FUNCCALLEXPR 24
#define ARGLIST 25
#define INTEGER 26
#define IDENTIFIER 27
#define VAR 28
#define ARRAYDECL 29
#define CHAR 30
#define FUNCTYPENAME 31

static FILE *out;
static int labelCounter = 0;

void genNode(tree *node);
void genStatement(tree *node);
char *genExpr(tree *node);

void codegen(tree *root) {
    out = fopen("out.s", "w");

    if (out == NULL) {
        perror("Could not open out.s");
        exit(1);
    }

    fprintf(out, ".text\n");
    fprintf(out, ".globl main\n\n");

    genNode(root);

    fclose(out);
}

void genNode(tree *node) {
    if (node == NULL) return;

    switch (node->nodeKind) {
        case PROGRAM:
        case DECLLIST:
        case DECL:
        case STATEMENTLIST:
        case STATEMENT:
        case COMPOUNDSTMT:
        case LOCALDECLLIST:
            for (int i = 0; i < node->numChildren; i++) {
                genNode(getChild(node, i));
            }
            break;

        case FUNDECL:
            // generate function label + body
            break;

        case FUNBODY:
            for (int i = 0; i < node->numChildren; i++) {
                genNode(getChild(node, i));
            }
            break;

        case ASSIGNSTMT:
            // genAssign(node);
            break;

        case CONDSTMT:
            // genIf(node);
            break;

        case LOOPSTMT:
            // genWhile(node);
            break;

        case RETURNSTMT:
            // genReturn(node);
            break;

        default:
            break;
    }
}