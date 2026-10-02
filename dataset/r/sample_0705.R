hash_function <- function(data, rounds = 1000) {
  if (rounds == 0) {
    return(data)
  }
  result <- 0
  for (char in strsplit(data, NULL)[[1]]) {
    result <- result + (charToRaw(char) * (rounds + charToRaw(char)))
  }
  return(hash_function(as.character(result), rounds - 1))
}

encrypt <- function(data, key) {
  if (nchar(data) == 0) {
    return('')
  }
  return(intToUtf8((utf8ToInt(substr(data, 1, 1)) + key) %% 256) %>% 
         paste(encrypt(substr(data, 2, nchar(data)), key), sep = ''))
}

main <- function() {
  data <- 'securedata'
  key <- 7
  hashed_data <- hash_function(data)
  encrypted_data <- encrypt(hashed_data, key)
  print(encrypted_data)
}

main()