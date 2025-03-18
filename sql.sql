# https://marketplace.visualstudio.com/items?itemName=cweijan.vscode-mysql-client2
# ^great extension

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
select prijmeni, jmeno, adresa from ctenari where adresa in ('Brno', 'Kurim');
select * from ctenari where prijmeni like 'H%';
select distinct jmeno from ctenari;
select jmeno, prijmeni from ctenari where adresa = 'brno';
select jmeno, prijmeni from ctenari where adresa in ('brno');
select distinct nazev, autor from knihy where autor in ('Hrabal', 'Viewegh');
select nazev, rok_vydani from knihy where rok_vydani between 1980 and 2010;

#as
select idk as signaturam, autor, nazev, dat_porizeni as 'from' from knihy;

# order by
select * from knihy order by autor, nazev;
select * from knihy order by dat_porizeni, rok_vydani;
select * from knihy order by rok_vydani, dat_porizeni;
select * from knihy order by rok_vydani desc, dat_porizeni desc;

select jmeno, prijmeni, dat_narozeni from ctenari where dat_narozeni > '1980-01-01' ORDER BY prijmeni;

# min, max, count, avg, sum

select count(*) as 'pocet registrovasnych ctenaru' from ctenari;
select count(idk), autor from knihy where autor = 'Capek';
# only counts not null
select count(autor), autor from knihy where autor = 'Capek'; 
select min(dat_porizeni) as nejstarsi_kniha from knihy;

# group by (plati pro funkce)
select count(*), adresa from ctenari GROUP BY adresa;
select autor, count(*) as pocet_knih from knihy group by autor;
select min(dat_narozeni) as nejstarsi_datum_narozeni from ctenari;
select * from ctenari;

# eqiuivalent
select autor, count(*) as pocet_knih from knihy group by autor having pocet_knih > 1;
select autor, count(*) as pocet_knih from knihy group by autor having count(*) > 1;

# join 
select distinct jmeno, prijmeni from vypujcky join ctenari on ctenari.idc = vypujcky.idc;
select distinct jmeno, prijmeni, nazev, autor from vypujcky join ctenari on ctenari.idc = vypujcky.idc join knihy on knihy.idk = vypujcky.idk;
select count(*) jmeno, prijmeni, nazev, autor from vypujcky join ctenari on ctenari.idc = vypujcky.idc join knihy on knihy.idk = vypujcky.idk group by vypujcky.idc;


update ctenari set adresa="blansko" where prijmeni="Mala";
SELECT * from ctenari;

delete from ctenari where prijmeni="Horak";

delete from vypujcky where idc = (select idc from ctenari where prijmeni="Mala");
select * from vypujcky;