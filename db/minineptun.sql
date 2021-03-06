﻿USE master;

DROP DATABASE minineptun2;

CREATE DATABASE minineptun2;

USE minineptun2;

CREATE TABLE [HALLGATOK] (
  [NEPTUN_KOD] CHAR(6) NOT NULL UNIQUE,
  [VNEV] NVARCHAR(50) NOT NULL,
  [KNEV] NVARCHAR(50) NOT NULL,
  [EMAIL] VARCHAR(50) NOT NULL,
  [SZUL_DATUM] DATE NOT NULL,
  [SZUL_HELY] NVARCHAR(50) NOT NULL,
  [FIU] BIT NOT NULL DEFAULT 1,
  [IRSZ] CHAR(4) NOT NULL,
  [TELEPULES] NVARCHAR(50) NOT NULL,
  [CIM] NVARCHAR(150) NOT NULL,
  [MEGJEGYZES] NVARCHAR(MAX) NULL,
  [ID] INT NOT NULL IDENTITY,
PRIMARY KEY(NEPTUN_KOD)
);

CREATE TABLE [TARGYAK] (
  [KOD] VARCHAR(20) NOT NULL UNIQUE,
  [NEV] NVARCHAR(50) NOT NULL,
  [KREDIT] TINYINT NOT NULL,
  [TKOV] CHAR(1) NOT NULL,
PRIMARY KEY(KOD)
);

CREATE TABLE [JEGYEK] (
  [HALLGATO_KOD] CHAR(6) NOT NULL UNIQUE,
  [TARGY_KOD] VARCHAR(20) NOT NULL,
  [JEGY] TINYINT NOT NULL,
  [UTVIZSGA] TINYINT NOT NULL,
  [DATUM] DATE NOT NULL DEFAULT GETDATE(),
PRIMARY KEY(HALLGATO_KOD, TARGY_KOD)
);

ALTER TABLE JEGYEK
  ADD CONSTRAINT FK_JEGYEK_HALLGATO FOREIGN KEY(HALLGATO_KOD)
  REFERENCES HALLGATOK(NEPTUN_KOD) ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE JEGYEK
  ADD CONSTRAINT FK_JEGYEK_TARGY FOREIGN KEY(TARGY_KOD)
  REFERENCES TARGYAK(KOD) ON DELETE CASCADE ON UPDATE CASCADE;

CREATE INDEX IX_HALLGATOK_VNEV ON HALLGATOK(VNEV);
CREATE INDEX IX_HALLGATOK_KNEV ON HALLGATOK(KNEV);
CREATE INDEX IX_TARGYAK_VNEV ON TARGYAK(NEV);

INSERT INTO HALLGATOK (NEPTUN_KOD, VNEV, KNEV, EMAIL, SZUL_DATUM, SZUL_HELY, FIU, IRSZ, TELEPULES, CIM, MEGJEGYZES)
  VALUES ('DT123W', N'Kiss', N'Géza', 'kiss.geza@valami.hu', '2000-07-26', N'Itt', DEFAULT, '1100', N'Valahol itten', N'Nincs megadva', N'');


INSERT INTO HALLGATOK (NEPTUN_KOD, VNEV, KNEV, EMAIL, SZUL_DATUM, SZUL_HELY, FIU, IRSZ, TELEPULES, CIM, MEGJEGYZES)
  VALUES ('DT123W', N'Nagy', N'János', 'nagy.ja@valami.hu', '2002-03-22', N'Győr', DEFAULT, '2012', N'Valahoasd al Nem', N'Nincs megadva', N'');

INSERT INTO HALLGATOK (NEPTUN_KOD, VNEV, KNEV, EMAIL, SZUL_DATUM, SZUL_HELY, FIU, IRSZ, TELEPULES, CIM, MEGJEGYZES)
  VALUES ('DT123W', N'Kiss', N'Géza', 'valami.jancsi@valami.hu', '2002-02-20', N'Budapest', DEFAULT, '', N'Valaholasd as itten', N'Nincs megadva', N'');

/* takacsg@sze.hu */