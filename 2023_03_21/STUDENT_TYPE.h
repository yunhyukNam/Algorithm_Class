#pragma once

typedef struct _PROFILE_{
    char name[32];
    int age;
    double height;
} PROFILE;

typedef struct _STUDENT_{
    PROFILE pf;
    int id;
    double grade;
} STUDENT;

typedef struct STUDENT{
    char name[32];
    int id;
    char major[32];
    int age;
    char address[32];
} STU;

typedef struct PROFILE{
    char name[32];
    double grade;
    int english;
} PROF;