Rails.application.routes.draw do


  resources :livros
  resources :users

  resources :sessions do
    collection do
      match 'search' => 'sessions#search', via: [:get, :post], as: :search
    end
  end

  root 'sessions#index'

  get    'homeUser'  => 'users#index'
  get    'search'  => 'sessions#show'
  get    'signup'  => 'users#new'
  get    'login'   => 'sessions#new'
  post   'login'   => 'sessions#create'
  delete 'logout'  => 'sessions#destroy'


  get 'sessions/search'

end
