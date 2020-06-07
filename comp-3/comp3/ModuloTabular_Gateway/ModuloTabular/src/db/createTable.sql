CREATE TABLE public.comodo
(
  descricao character varying(32) NOT NULL,
  id integer NOT NULL DEFAULT nextval('comodo_id_seq'::regclass),
  tipo_comodo character varying(32) NOT NULL,
  CONSTRAINT "PK_ID" PRIMARY KEY (id)
)

CREATE TABLE public.mobilia
(
  descricao character varying(32) COLLATE pg_catalog."C.UTF-8" NOT NULL,
  id integer NOT NULL DEFAULT nextval('mobilia_id_seq'::regclass),
  custo real NOT NULL,
  tempoentrega integer NOT NULL,
  CONSTRAINT unique_id UNIQUE (id)
)

CREATE TABLE public.comodo_composto
(
  id_comodo_associado integer,
  id_comodo integer,
  id integer NOT NULL DEFAULT nextval('comodo_composto_id_seq'::regclass),
  CONSTRAINT "FK_COMODO" FOREIGN KEY (id_comodo)
      REFERENCES public.comodo (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION,
  CONSTRAINT "FK_COMODO_ASSOCIADO" FOREIGN KEY (id_comodo_associado)
      REFERENCES public.comodo (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION
)

CREATE TABLE public.comodo_mobilia
(
  id_comodo integer NOT NULL,
  id_mobilia integer NOT NULL,
  CONSTRAINT "FK_ID_MOBILIA" FOREIGN KEY (id_mobilia)
      REFERENCES public.mobilia (id) MATCH SIMPLE
      ON UPDATE NO ACTION ON DELETE NO ACTION
)