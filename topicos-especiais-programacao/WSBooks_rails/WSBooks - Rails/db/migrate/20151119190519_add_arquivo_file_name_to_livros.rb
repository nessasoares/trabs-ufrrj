class AddArquivoFileNameToLivros < ActiveRecord::Migration
  def change
    add_column :livros, :arquivo_file_name, :string
  end
end
