# Print all todo messages with their respective file location and line

Path.wildcard("../src/**")
|> Enum.filter(&File.regular?/1)
|> Enum.each(fn file ->
  File.stream!(file)
  |> Stream.with_index(1)
  |> Enum.each(fn {line, i} ->
    if String.contains?(line, "TODO") do
      IO.puts("#{file}:#{i}: #{String.trim(line)}")
    end
  end)
end)
