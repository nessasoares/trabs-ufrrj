-------------------------------DELETE ------------------------
delete from "comodo_composto" where id is not null
delete from "comodo_mobilia" where id_comodo is not null
delete from "item_venda" where id is not null
delete from "comodo" where id is not null
delete from "mobilia" where id is not null
delete from "ambiente" where id is not null
delete from "contrato" where id is not null


--------------------------------------------------------------


select cm.id_comodo, cm.id_mobilia, c.descricao_comodo, c.tipo_comodo,  m.descricao_mobilia
from "comodo_mobilia" as cm, 
"comodo" as c, 
"mobilia" as m 
where cm.id_comodo = c.id
and cm.id_mobilia = m.id

select cm.id_mobilia, m.descricao_mobilia, m.custo, m.tempoentrega from "comodo_mobilia" as cm, "mobilia" as m where id_comodo = 112 and cm.id_mobilia = m.id

alter table "ambiente" add column id Serial not null

select c.id from "comodo" as c where id = 112

INSERT INTO "comodo_mobilia" (id_mobilia, id_comodo) VALUES ((select id from "mobilia" order by id desc limit 1), (select c.id from "comodo" as c where id = 112));

select id from ambiente order by id desc limit 1

select cm.id_comodo, cm.id_mobilia, c.descricao_comodo, c.tipo_comodo,  m.descricao_mobilia
from "comodo_mobilia" as cm, 
"comodo" as c, 
"mobilia" as m 
where cm.id_comodo = c.id
and cm.id_mobilia = m.id

select cm.id_mobilia, m.descricao_mobilia, m.custo, m.tempoentrega from "comodo_mobilia" as cm, "mobilia" as m where id_comodo = 112 and cm.id_mobilia = m.id

alter table "ambiente" add column id Serial not null

select c.id from "comodo" as c where id = 112

INSERT INTO "comodo_mobilia" (id_mobilia, id_comodo) VALUES ((select id from "mobilia" order by id desc limit 1), (select c.id from "comodo" as c where id = 112));

ALTER TABLE public.item_venda
  ADD CONSTRAINT "FK_mobilia" FOREIGN KEY (id_mobilia)
      REFERENCES public.mobilia (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE no action;


ALTER TABLE public.item_venda
  ADD CONSTRAINT "FK_ambiente" FOREIGN KEY (id_ambiente)
      REFERENCES public.ambiente (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE public.comodo_mobilia
  ADD CONSTRAINT "FK_ID_MOBILIA" FOREIGN KEY (id_mobilia)
      REFERENCES public.mobilia (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE public.comodo_composto
  ADD CONSTRAINT "FK_COMODO_ASSOCIADO" FOREIGN KEY (id_comodo_associado)
      REFERENCES public.comodo (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION;

   ALTER TABLE public.comodo_composto
  ADD CONSTRAINT "FK_COMODO" FOREIGN KEY (id_comodo)
      REFERENCES public.comodo (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION;
   
      
  alter table "contrato" add column id Serial not null

delete from contrato where id is not null

select * from item_venda
insert into "contrato" (prazo) values (0);

select * from mobilia order by tempoentrega;

select m.tempoentrega from mobilia as m, item_venda as i, ambiente as a where i.id_mobilia = m.id 
and i.id_ambiente=122;

select id from ambiente order by id desc limit 1

SELECT * FROM item_venda where id_ambiente = 122;

SELECT max(m.tempoentrega)
FROM mobilia as m
INNER JOIN item_venda as i
ON i.id_mobilia=m.id and i.id_ambiente= (select id from ambiente order by id desc limit 1);

RIGHT JOIN ambiente as a
ON i.id_ambiente = 122;
      