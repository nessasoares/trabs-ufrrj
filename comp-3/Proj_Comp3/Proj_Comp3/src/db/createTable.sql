
CREATE TABLE public.mobilia
(
  id integer NOT NULL DEFAULT nextval('cozinha_id_seq'::regclass),
  "desc" character varying(32) NOT NULL,
  "comodoAssociado" character varying(32) NOT NULL
)

CREATE TABLE public.comodo
(
  id integer NOT NULL DEFAULT nextval('cozinha_id_seq'::regclass),
  tipo character varying(32) NOT NULL,
  descricao character varying(32)
)

CREATE TABLE public.cozinha
(
  descricao character varying(32) COLLATE pg_catalog."C.UTF-8",
  id integer NOT NULL DEFAULT nextval('cozinha_id_seq'::regclass),
  CONSTRAINT cozinha_pkey PRIMARY KEY (id)
)

CREATE TABLE public.quarto
(
  id integer NOT NULL DEFAULT nextval('cozinha_id_seq'::regclass),
  descricao character varying(32) COLLATE pg_catalog."C.UTF-8" NOT NULL,
  CONSTRAINT quarto_pkey PRIMARY KEY (id)
)