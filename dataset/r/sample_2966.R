SequenceParser <- setRefClass("SequenceParser",
                              fields = list(text = "character", tokens = "list", index = "numeric"),
                              methods = list(
                                initialize = function(text) {
                                  .self$text <- text
                                  .self$tokens <- list()
                                  .self$index <- 1
                                },
                                tokenize = function() {
                                  while (.self$index <= nchar(.self$text)) {
                                    char <- substr(.self$text, .self$index, .self$index)
                                    if (grepl("\\d", char)) {
                                      .self$tokens <- c(.self$tokens, .self$parse_number())
                                    } else if (grepl("[a-zA-Z]", char)) {
                                      .self$tokens <- c(.self$tokens, .self$parse_word())
                                    } else if (!grepl("\\s", char)) {
                                      .self$tokens <- c(.self$tokens, char)
                                    }
                                    .self$index <- .self$index + 1
                                  }
                                },
                                parse_number = function() {
                                  start <- .self$index
                                  while (.self$index <= nchar(.self$text) && grepl("\\d", substr(.self$text, .self$index, .self$index))) {
                                    .self$index <- .self$index + 1
                                  }
                                  return(substr(.self$text, start, .self$index - 1))
                                },
                                parse_word = function() {
                                  start <- .self$index
                                  while (.self$index <= nchar(.self$text) && grepl("[a-zA-Z]", substr(.self$text, .self$index, .self$index))) {
                                    .self$index <- .self$index + 1
                                  }
                                  return(substr(.self$text, start, .self$index - 1))
                                }
                              ))

SequenceProcessor <- setRefClass("SequenceProcessor",
                                fields = list(parser = "SequenceParser", processed = "list"),
                                methods = list(
                                  initialize = function(parser) {
                                    .self$parser <- parser
                                    .self$processed <- list()
                                  },
                                  process = function() {
                                    for (token in .self$parser$tokens) {
                                      if (grepl("\\d", token)) {
                                        .self$processed <- c(.self$processed, as.integer(token) * 2)
                                      } else if (grepl("[a-zA-Z]", token)) {
                                        .self$processed <- c(.self$processed, toupper(token))
                                      } else {
                                        .self$processed <- c(.self$processed, token)
                                      }
                                    }
                                  }
                                ))

SequenceDisplay <- setRefClass("SequenceDisplay",
                              fields = list(processor = "SequenceProcessor"),
                              methods = list(
                                initialize = function(processor) {
                                  .self$processor <- processor
                                },
                                display = function() {
                                  while (TRUE) {
                                    for (item in .self$processor$processed) {
                                      cat(item, sep = " ")
                                    }
                                    cat("\n")
                                  }
                                }
                              ))

main <- function() {
  text <- 'hello 123 world 456'
  parser <- SequenceParser$new(text)
  parser$tokenize()
  processor <- SequenceProcessor$new(parser)
  processor$process()
  display <- SequenceDisplay$new(processor)
  display$display()
}

main()