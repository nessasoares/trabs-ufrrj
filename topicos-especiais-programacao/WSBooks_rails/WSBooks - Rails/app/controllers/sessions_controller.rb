class SessionsController < ApplicationController
  def new
  end

  def create
    @user = User.find_by_email(params[:session][:email])
    if @user && @user.authenticate(params[:session][:password])
      session[:user_id] = @user.id
      redirect_to '/homeUser'
    else
      flash.now[:error] = "Could not create client"
      redirect_to 'login'
    end
  end


  def destroy
    session[:user_id] = nil
    redirect_to '/'
  end

  def index
  end


  def show

#      busca_titulo = params[:search_titulo].to_s
 #     @livros = Livro.where("titulo LIKE ?","%#{busca_titulo}%")

    @q = Livro.ransack(params[:q].try(:merge, m: 'and' ))
    @livros = @q.result



  end


  def search
    show
    render :show
  end

  end
