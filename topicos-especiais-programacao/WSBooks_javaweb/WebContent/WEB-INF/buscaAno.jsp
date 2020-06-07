<form class="navbar-form navbar-left" role="search" method='get' action='servletBuscaLivro'>
     <div class="form-group">
         <input type="text"  name= "ano" id="inputAno" class="form-control" placeholder="digite o ano AAAA">
     </div>
     <button type="submit" class="btn btn-default">Buscar</button>                              
     <br>
     <div class="sidebar blog-sidebar">
         <div class="sidebar-item  recent">
             
             <c:forEach var = "book" items = "${listaLivroAno}" >
             
                <div class="media">
                   <div class="pull-left">
                         <a href="livro.jsp"><img src="multicolor-4/images/books/${book.arquivo}" alt=""></a>
                    </div> 
                     <div class="media-body">
                         <h4><a href="#">${book.titulo}</a></h4>
                         <p>${book.autor}</p>
                         <p>${book.ano}</p>
                     </div>
               </div>
              </c:forEach>
         </div>
     </div>
    <!-- <div class="blog-pagination">
        <ul class="pagination">
          <li><a href="#">left</a></li>
          <li><a href="#">1</a></li>
          <li><a href="#">2</a></li>
          <li class="active"><a href="#">3</a></li>
          <li><a href="#">4</a></li>
          <li><a href="#">5</a></li>
          <li><a href="#">6</a></li>
          <li><a href="#">7</a></li>
          <li><a href="#">8</a></li>
          <li><a href="#">9</a></li>
          <li><a href="#">right</a></li>
        </ul>
    </div>-->
</form>