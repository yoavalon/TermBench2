DocumentParser <- setRefClass("DocumentParser",
  fields = list(
    text = "character",
    tokens = "character"
  ),
  methods = list(
    tokenize = function() {
      library(stringr)
      self$tokens <- str_extract_all(tolower(self$text), "\\b\\w+\\b")[[1]]
    },
    filter_tokens = function() {
      stop_words <- c('the', 'and', 'is', 'in', 'to', 'a', 'of', 'it', 'that', 'for', 'on', 'with', 'as', 'by', 'at', 'from', 'this', 'an', 'or', 'but', 'not', 'are', 'be', 'was', 'were', 'has', 'have', 'had', 'do', 'does', 'did', 'will', 'would', 'can', 'could', 'should', 'if', 'then', 'else', 'while', 'when', 'where', 'who', 'what', 'why', 'how', 'all', 'any', 'each', 'few', 'more', 'most', 'other', 'some', 'such', 'no', 'nor', 'only', 'own', 'same', 'so', 'than', 'too', 'very', 's', 't', 'can', 'will', 'just', 'don', 'should', 'now')
      self$tokens <- self$tokens[!self$tokens %in% stop_words]
    }
  )
)

DataMutator <- setRefClass("DataMutator",
  fields = list(
    tokens = "character",
    mutated_tokens = "character"
  ),
  methods = list(
    mutate = function() {
      library(dplyr)
      self$mutated_tokens <- sapply(self$tokens, function(token) {
        if (sample(c(TRUE, FALSE), 1)) {
          return(rev(unlist(strsplit(token, ""))) %>% paste(collapse = ""))
        } else {
          return(token)
        }
      })
    }
  )
)

main <- function() {
  text <- 'Document parsing and lexical tokenization are important for natural language processing tasks.'
  parser <- DocumentParser$new(text = text)
  parser$tokenize()
  parser$filter_tokens()
  mutator <- DataMutator$new(tokens = parser$tokens)
  mutator$mutate()
  print(mutator$mutated_tokens)
}

main()