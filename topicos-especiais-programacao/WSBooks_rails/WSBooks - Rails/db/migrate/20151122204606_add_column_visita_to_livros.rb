class AddColumnVisitaToLivros < ActiveRecord::Migration
  def change
    add_column :livros, :visita, :integer
  end
end
