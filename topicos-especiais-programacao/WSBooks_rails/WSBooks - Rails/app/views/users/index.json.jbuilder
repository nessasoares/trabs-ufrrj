json.array!(@users) do |user|
  json.extract! user, :id, :name, :password, :username, :email, :sexo
  json.url user_url(user, format: :json)
end
