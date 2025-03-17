CREATE TABLE ctenari
(
  idc int PRIMARY KEY,
  jmeno varchar(255),
  prijmeni varchar(255),
  adresa varchar(255),
  dat_narozeni date
);


INSERT INTO ctenari VALUES
(1, 'Petr', 'Horak', 'Brno', '1990-12-12'),
(2, 'Jana', 'Mala', 'Kurim', '1980-04-20'),
(3, 'Martin', 'Cerny', 'Tisnov', '1978-08-30');


CREATE TABLE  knihy
(
  idk int(11) PRIMARY KEY,
  nazev varchar(255),
  autor varchar(255),
  rok_vydani int(11),
  dat_porizeni date
);

INSERT INTO knihy VALUES
(1, 'Krakatit', 'Capek', 2000, '2010-10-15'),
(2, 'RUR', 'Capek', 1990, '2012-11-10'),
(3, 'Postriziny', 'Hrabal', 1980, '2010-05-15'),
(4, 'Ostre sledovane vlaky', 'Hrabal', 1970, '2014-12-07'),
(5, 'Bajecna leta pod psa', 'Viewegh', 2000, '1998-10-20');


CREATE TABLE vypujcky
(
  idc int,
  idk int
);


INSERT INTO vypujcky VALUES
(1, 1),
(1, 2),
(2, 3),
(3, 4),
(2, 5);

describe knihy;

select distinct autor from knihy;
select nazev from knihy where (autor = 'capek');
select * from knihy where (dat_porizeni > '2010-01-01');
select jmeno, prijmeni from ctenari where (adresa = 'brno') and (dat_narozeni > '1990-01-01');
select * from knihy where rok_vydani between 1975 and 1995;