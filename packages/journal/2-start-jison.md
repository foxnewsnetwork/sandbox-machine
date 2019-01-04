# Getting Started With Jison

Consult the ultimate bison docs [here][22]

Naturally, as I learn more about computer science, I would need to learn more computer languages; and using [jison][1] to build some basic calculator or compiler would be a great way to get my feet wet in the world of programming languages. This journal entry will be my first foray into building a compiler that translates a language into javascript. 

The ultimate goal of this project would be the creation of a ML-enabled meta-compiler that puts together to-js application-specific compilers. The code for this lives [here](../ailang)

## Introduction to Backus-Naur Form

Backus-Naur form is a meta-language for describing grammars using regular expressions as per [this video][6]. Reading the [wiki page][8] and the [extended wiki][7], I'm noticing that BNF resembles a *lot* what a typed language (e.g. haskell) looks like. Perhaps it's not a surprise that the "ML" part of "ocaml" stands for "meta-language"

Consider the following diagram (written in [dot][9]):

```dot
digraph BNF {
  Named -> Nonterminal
  Character -> Nonterminal
  Literal -> Nonterminal
  Nonterminal -> Nonterminal
  Nonterminal -> Expression
  Expression -> Expression
  Expression -> Nonterminal
  Expression -> Program
}
```

- Tokens eventually become numbers by the parser / language
- Philosophically, tokens are "meaningful" clusterings of input (both data and program) that allow for "emergence" of higher level behaviors from lower level simpler parts
- At the end of the day, the parser outputs 1 expression that leads to 1 action when executed (with possible additional input). This is what we ultimately call a "program"
- Expressions may perform "actions" (what I frequently think of as IO), this is where the language interfaces with the "substrate" that it lives on and affects the underlying physical media
  - For example, if someone tells me to "raise your hand", the program in my brain lexes, parses, then executes the input and generates motor signals that target the phyiscal "substrate" that is muscles in my arm to pull / relax in such an order that the end result is I raise my hand

Let's move onto using Bison to generate grammars

## Introduction to Bison

From the [bison docs][3]:

- Named Tokens
  - Operator-like things with names
  - See [calculator example][10]
- Character Tokens
- String Literal Tokens

However, with further reading, it seems the above are more "conventions" than actual bison syntax; instead, bison gives the following methods for declaring tokens in their [declaration summary][11]:

- `%token`
- `%union`
- ... others

Consider the `%token` "function type"

```reasonml
type token = {
  name: string,
  representation: string
}
```

For example, we have:

```bison
%token ARROW "=>"
%token  <operator>  OR      "||"
%token  <operator>  LTE 134  "<="
%left  OR  "<="
```

the `<operator>` specifies type of token - whatever that means - see [here][12]

### The Deal with Operator Precedence

We have 3 types of precedence to deal with in-fixing of operators and nesting

- `%left`
- `%right`
- `%nonassoc` 

Using their example [here][13], say we have the following:

```bison
%left PLUS "+" 
```
And the expression "4+5+6", we would get:

```dot
digraph "4+5+6" {
  "+" -> "4+5"
  "+" -> "6"
}
```

Whereas if we had `%right PLUS "+"`, the association would go "the other way"

```dot
digraph "4+5+6" {
  "+" -> "4"
  "+" -> "5+6"
}
```

If we use `%nonassoc PLUS "+"`, then we would get a syntax error

>Note: the later the declaration, the higher the precedence

### The Deal with Unions

These things are apparently a way to declare additional "types" - whatever those are. Read more about unions and types on [their site here][15]. I'm not going to go into details on that stuff here because it doesn't seem like I'll need it (especially after viewing examples)

## Usage Example In Real LIfe

- A much more illustrative example, check out the grammar for [javascript][14]
- [Coffeescript grammar][15]
  - Note that coffeescript implements their own [lexer][16] instead of using jison's
  - This is because they presumably want to handle space and indentation better

Here are some of my takeaways

- `%start` is a program's entry point, ever grammar requires one
- it's the lexer's job to "lex" the input string into consumable tokens for the parser, this is why we see a lot of things like `POST_IF`, `IF`, `ELSE`, and other random floating strings in the grammar syntax without references to "if" and stuff - this is because all the lexing was done ahead of time!
  - This means that whatever I declare under the `token` section, I should respect in my lexer!

First things first, I want to get a "hello world" example going by setting up my local environment to be able to work. Following the directions on the [jison github landing page][4], I will attempt to follow along with the [calculator example][5]

## On Jison Paramters

The parser is essentially a glorified series of function calls, and it seems here are its parameters:

```typescript
type action<SharedState> = (
  yytext: string, 
  yyleng: number, 
  yylineno: number, 
  yy: SharedState, 
  yystate, 
  $$, 
  _$
) => any
```

So what's the deal with all the "yy" stuff? read about it [here][18]

Apparently, the `yy` stuff all come from [bison action constructs][21]; at the end of the day, actions are simply different ways of invoking a function

In any case, it's relatively simple to use the jison to build a parser; go into the `ailang` directory and run `yarn run make:calculator` to bake one into the `dist` directory

# Appendix

As usual, the appendix carries content interesting or relevant here, but doesn't fit directly into the exact up-top themed narrative

## A1 - On How Compilers Bootstrap Themselves

One of the really weird things about modern production-tier programming languages is that, if you look at their github source, it seems the language is written in the language itself - which is ridiculous as this is clearly an infinite regress and absolutely begs the question of how such a system could get started in the first place.

Consider the case of [rustlang][20], According to the breakdown, it seems rust is written in ~97% rust itself, which makes no sense. After a bit of digging, apparently, the rust compiler is a series of stages that compiles a compiler for the next stage 

According to [this comment][19], it seems stage0 rust compiler was written in ocaml some time ago; anyway, consider the diagram:

```dot
digraph rust {
  ocaml -> stage0
  stage0 -> cargo
  cargo -> "compile.rs"
  "compile.rs" -> "stdlib"
}
```

In general, this seems to be order of how seeming self-implementing languages bootstrap themselves - they all start from some other language

## A2 - Jison's Parse Function

[jison's parse function][23] introduces a number of javascript notations that I am *not* familar with, notably:

```javascript
function parse(x) {
  before:
    console.log(x);

  success:
    return "success";
  
  error:
    return "error";
}
```

What does this even do? Running this in my browser gets me the following:

```sh
$ parse(234)
234
"success"
```

Note that this is apparently not a strict mode thing as adding in `"use strict";` does nothing.

After some research, apparently these are called [labels][24], and are a way for loops to "goto" each other.

In jison, the labels are used around [json selection](https://github.com/zaach/jison/blob/bcf986e180359aa2404b1b73ecbfef1df4c6b011/lib/jison.js#L1091) such as:

```javascript
var labeled = JSONSelect.match(':has(:root > .label > .name:val("_token_stack"))', ast);
```

Apparently, this is how one achieves "metaprogramming" in the world of javascript (cool, but dangerous!)

Read more about [jsonselect here][25]; I would *NOT* recomend using though, while intelligence does arise from meta-programming, it does make the program opaque as all hell as we're now dependent upon emergence for computer behavior

# References

As usual, see this page in raw to view my bibliography

[1]: <https://zaa.ch/jison/docs/> "Jison Landing Page"
[2]: <http://dinosaur.compilertools.net/bison/bison_4.html#SEC7> "Bison Concepts"
[3]: <http://dinosaur.compilertools.net/bison/bison_6.html#SEC34> "Bison Grammar Files"
[4]: <https://github.com/zaach/jison> "Jison Github Page"
[5]: <https://github.com/zaach/jison/blob/master/examples/calculator.jison> "Jison Calculator Example Grammar"
[6]: <https://www.youtube.com/watch?v=U7X6tDYwmdM> "Introduction to BNF"
[7]: <https://en.wikipedia.org/wiki/Extended_Backus%E2%80%93Naur_form> "Extended BNF"
[8]: <https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form> "BNF"
[9]: <https://en.wikipedia.org/wiki/DOT_(graph_description_language)> "Dot Language for Graph Visualization"
[10]: <https://github.com/zaach/jison/blob/bcf986e180359aa2404b1b73ecbfef1df4c6b011/examples/calculator.jison#L28-L33> "Operator Named Token Example"
[11]: <http://dinosaur.compilertools.net/bison/bison_6.html#SEC57> "Bison Declaration Summary"
[12]: <http://dinosaur.compilertools.net/bison/bison_6.html#SEC45> "Tokens with more than 1 type"
[13]: <http://dinosaur.compilertools.net/bison/bison_6.html#SEC51> "On operator precedence"
[14]: <https://github.com/zaach/jison/blob/master/examples/jscore.jison> "Js Core Jison Example"
[15]: <http://dinosaur.compilertools.net/bison/bison_6.html#SEC52> "Collection Values and Unions in Bison"
[16]: <https://coffeescript.org/v1/annotated-source/grammar.html> "Grammar of Coffeescript"
[17]: <https://coffeescript.org/v1/annotated-source/lexer.html> "Coffeescript Lexer"
[18]: <http://zaa.ch/jison/docs/#sharing-scope> "Sharing scope aka all the yy stuff"
[19]: <https://github.com/rust-lang/rust/issues/40991#issuecomment-290917501> "Some dude comments on the history of rust compiler bootstraping itself"
[20]: <https://github.com/rust-lang/rust> "Rust Language Github"
[21]: <http://www.gnu.org/software/bison/manual/html_node/Action-Features.html#Action-Features> "Bison Action Constructs"
[22]: <http://www.gnu.org/software/bison/manual/html_node/index.html#SEC_Contents> "GNU Bison Docs Table of Contents"
[23]: <https://github.com/zaach/jison/blob/bcf986e180359aa2404b1b73ecbfef1df4c6b011/lib/jison.js#L1370-L1607> "Jison's confusing parse function"
[24]: <https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/label> "JavaScript labeled loops"
[25]: <https://github.com/lloyd/JSONSelect/blob/master/JSONSelect.md> "JSONSelect - aka how to metaprogram in js"
