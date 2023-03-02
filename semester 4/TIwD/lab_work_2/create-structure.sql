CREATE TABLE "user" (
    "id"                  SERIAL   PRIMARY KEY,
    "login"               TEXT     NOT NULL UNIQUE,
    "password"            TEXT     NOT NULL,
    "role"                SMALLINT NOT NULL CHECK ("role" IN (1, 2, 3))
    /*
        1 - ADMIN
        2 - DOCTOR
        3 - PATIENT
    */
);

CREATE TABLE "doctor" (
    "id"                  INTEGER  PRIMARY KEY REFERENCES "user"    ON UPDATE RESTRICT ON DELETE CASCADE, /* связь один-к-одному */
    "name"                TEXT     NOT NULL,
    "surname"             TEXT     NOT NULL,
    "patronymic"          TEXT     NOT NULL, 
    "birthday"            DATE     NOT NULL,
    "id_speciality"       INTEGER  NOT NULL REFERENCES "speciality" ON UPDATE RESTRICT ON DELETE RESTRICT

);

CREATE TABLE "patient" (
    "id"                  INTEGER  PRIMARY KEY REFERENCES "user"    ON UPDATE RESTRICT ON DELETE CASCADE, /* связь один-к-одному */
    "name"                TEXT     NOT NULL,
    "surname"             TEXT     NOT NULL,
    "patronymic"          TEXT     NOT NULL,
    "birthday"            DATE     NOT NULL,
    "gender"              TEXT     NOT NULL
);

CREATE TABLE "phone" (
    "number"              TEXT     PRIMARY KEY, /* пример строкового первичного ключа - лучше так не делать */
    "id"           INTEGER  NOT NULL REFERENCES "doctor"     ON UPDATE RESTRICT ON DELETE CASCADE
);

CREATE TABLE "speciality" (
    "id"             SERIAL   PRIMARY KEY,
    "name"                TEXT     NOT NULL
);

CREATE TABLE "card" (
    "id"                  SERIAL   PRIMARY KEY,
    "patient_id"          INTEGER  NOT NULL REFERENCES "patient"       ON UPDATE RESTRICT ON DELETE RESTRICT,
    "diadnosis_1"         TEXT NOT NULL,
    "diagnosis"           TEXT,
    "start-date"          DATE NOT NULL,
    "end_date"            DATE
);

CREATE TABLE "procedure" (
    "id"        SERIAL   PRIMARY KEY,
    "patient_id"          INTEGER  NOT NULL REFERENCES "card"     ON UPDATE RESTRICT ON DELETE RESTRICT,
    "date_start"          DATE     NOT NULL,
    "date_finish"         DATE     NOT NULL,
    "doctor_1_id"         INTEGER  NOT NULL REFERENCES "doctor"  ON UPDATE RESTRICT ON DELETE RESTRICT,
    "doctor_2_id"         INTEGER  NOT NULL REFERENCES "doctor"           ON UPDATE RESTRICT ON DELETE RESTRICT,
    "information"         TEXT     NOT NULL,
    "mark_finish"         TEXT

);

CREATE TABLE "inspection" (
    "id"                  SERIAL   PRIMARY KEY,
    "patient_id"          INTEGER  NOT NULL REFERENCES "card"     ON UPDATE RESTRICT ON DELETE RESTRICT,
    "date"                DATE     NOT NULL,
    "doctor_id"           INTEGER  NOT NULL REFERENCES "doctor"  ON UPDATE RESTRICT ON DELETE RESTRICT,
    "result"              TEXT NOT NULL
);
