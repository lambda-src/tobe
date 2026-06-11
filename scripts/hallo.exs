# Prints hello, world! (Very useful)

# This is piping where a |> b = b(a) or in this case the equivalence would be
# IO.puts(String.downcase("HELLO, WORLD!")) == "HELLO, WORLD!" |> String.downcase() |> IO.puts()
"HELLO, WORLD!" |> String.downcase() |> IO.puts()
