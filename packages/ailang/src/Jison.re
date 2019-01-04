type t;

type grammar;

[@bs.new]
[@bs.module "jison"]
external createParser : grammar => t = "Parser";

[@bs.send]
external parse : t => string => string = "parse";

[@bs.send]
external generate : t => string = "generate";