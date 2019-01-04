[@bs.module]
external calculatorGrammar : Jison.grammar = "./calculator.json";

let calculator : Jison.t = Jison.createParser(calculatorGrammar);

Js.log(Jison.generate(calculator));