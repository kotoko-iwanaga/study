enum class TokenType {
  illegal,
  eof,

  identifier,   // variable
  lparen,       // (
  rparen,       // )
  lsquirly,     // {
  rsquirly,     // }
  comma,        // ,
  semicolon,    // ;
  doublecolon,  // ::
  classt,
  structt,
  uniont,
  voidt,
  intt,
  chart,
  floatt,
  doublet,
  boolt,

  linecomment,
  longcomment,
};